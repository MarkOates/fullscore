


#include <fullscore/models/measure_grid.h>

#include <iostream>
#include <fullscore/models/note.h>



MeasureGrid::Row::Row(int num_measures) : measures()
{
   for (unsigned i=0; i<num_measures; i++) measures.push_back(nullptr);
}



Measure::Base *MeasureGrid::Row::operator[](unsigned int index)
{
   if (index >= measures.size()) std::cout << "measure index out of bounds" << std::endl;
   return measures[index];
}



MeasureGrid::MeasureGrid(int num_x_measures, int num_y_staves)
   : voices()
   , time_signatures()
{
   for (unsigned i=0; i<num_y_staves; i++) voices.push_back(Row(num_x_measures));
   time_signatures.resize(num_x_measures, TimeSignature(4, Duration()));
}



Measure::Base *MeasureGrid::get_measure(int x_measure, int y_staff)
{
   // bounds check
   if (x_measure < 0 || x_measure >= this->get_num_measures() || this->get_num_measures() == 0) return NULL;
   if (y_staff < 0 || y_staff >= this->get_num_staves() || this->get_num_staves() == 0) return NULL;

   return voices[y_staff][x_measure];
}



bool MeasureGrid::set_measure(int x_measure, int y_staff, Measure::Base *measure)
{
   // bounds check
   if (x_measure < 0 || x_measure >= this->get_num_measures() || this->get_num_measures() == 0) return false;
   if (y_staff < 0 || y_staff >= this->get_num_staves() || this->get_num_staves() == 0) return false;

   Measure::Base *existing_measure = get_measure(x_measure, y_staff);
   if (existing_measure) delete existing_measure;
   voices[y_staff].measures[x_measure] = measure;
   return true;
}



int MeasureGrid::get_num_measures() const
{
   if (voices.empty()) return 0;
   return voices[0].measures.size();
}



int MeasureGrid::get_num_staves() const
{
   return voices.size();
}



void MeasureGrid::insert_staff(int index)
{
   if (index < 0) index = 0;

   if (index >= (int)voices.size())
   {
      append_staff();
   }
   else 
   {
      int num_measures = (voices.empty()) ? 8 : voices[0].measures.size();
      voices.insert(voices.begin() + index, Row(num_measures)); 
   }
}



bool MeasureGrid::delete_staff(int index)
{
   if (index < 0 || index >= (int)voices.size()) return false;
   voices.erase(voices.begin() + index);
   return true;
}



void MeasureGrid::append_staff()
{
   int num_measures = (voices.empty()) ? 8 : voices[0].measures.size();
   voices.push_back(Row(num_measures));
}



void MeasureGrid::insert_measure(int index)
{
   int num_measures = get_num_measures();
   if (index < 0) index = 0;

   if (index >= num_measures)
   {
      append_measure();
   }
   else
   {
      // insert a time signature
      time_signatures.insert(time_signatures.begin() + index, TimeSignature(4, Duration()));

      // insert a measure into each row
      for (unsigned i=0; i<voices.size(); i++)
      {
         // WARNING: this assumes all staves have the same
         // number of measures (they should)
         voices[i].measures.insert(voices[i].measures.begin() + index, nullptr);
      }
   }
}



bool MeasureGrid::delete_measure(int index)
{
   int num_measures = get_num_measures();

   if (index < 0 || index >= num_measures) return false;

   // remove the time signature
   time_signatures.erase(time_signatures.begin() + index);

   // remove the measure from each row
   for (unsigned i=0; i<voices.size(); i++)
      voices[i].measures.erase(voices[i].measures.begin() + index);

   return true;
}



void MeasureGrid::append_measure()
{
   // append time signature
   time_signatures.push_back(TimeSignature(4, Duration()));

   // append measure to each row
   for (unsigned i=0; i<voices.size(); i++)
   {
      voices[i].measures.push_back(nullptr);
   }
}



bool MeasureGrid::set_voice_name(int row_number, std::string name)
{
   if (row_number < 0) return "";
   if (row_number >= voices.size()) return "";
   voices[row_number].name = name;
   return true;
}



std::string MeasureGrid::get_voice_name(int row_number)
{
   if (row_number < 0) return "";
   if (row_number >= voices.size()) return "";
   return voices[row_number].name;
}



bool MeasureGrid::set_time_signature(int index, TimeSignature time_signature)
{
   if (index < 0) return false;
   if (index >= get_num_measures()) return false;

   time_signatures[index] = time_signature;
   return true;
}



TimeSignature MeasureGrid::get_time_signature(int index)
{
   if (index < 0) return TimeSignature(0, Duration());
   if (index >= get_num_measures()) return TimeSignature(0, Duration());

   return time_signatures[index];
}



