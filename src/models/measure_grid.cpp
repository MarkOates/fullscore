


#include <fullscore/models/measure_grid.h>

#include <iostream>
#include <fullscore/models/note.h>



MeasureGrid::Row::Row(int num_measures) : measures()
{
   for (unsigned i=0; i<num_measures; i++) measures.push_back(nullptr);
}



Measure::Base *MeasureGrid::Row::get_measure(int x_measure)
{
   if (x_measure < 0 || x_measure >= measures.size()) return nullptr;
   return measures[x_measure];
}



MeasureGrid::MeasureGrid(int num_x_measures, int num_y_staves)
   : voices()
   , time_signatures()
{
   for (unsigned i=0; i<num_y_staves; i++) voices.push_back(new Row(num_x_measures));
   time_signatures.resize(num_x_measures, TimeSignature(4, Duration()));
}



Measure::Base *MeasureGrid::get_measure(int x_measure, int y_staff)
{
   // bounds check
   if (!in_grid_range(x_measure, y_staff)) return nullptr;

   Row *row = voices[y_staff];
   if (!row) return nullptr;

   return row->get_measure(x_measure);
}



bool MeasureGrid::set_measure(int x_measure, int y_staff, Measure::Base *measure)
{
   // bounds check
   if (!in_grid_range(x_measure, y_staff)) return false;

   Measure::Base *existing_measure = get_measure(x_measure, y_staff);
   if (existing_measure) delete existing_measure;
   // WARNING
   // this implementation directly assigns a measure to the voice, assuming
   // that a voice has measures, and the voice's measures are of Measure::Base type
   // this should likely be handled by a method on the Row, like
   // voices[i]->set_measure(x_measure, measure);
   voices[y_staff]->measures[x_measure] = measure;
   return true;
}



bool MeasureGrid::delete_measure(int x_measure, int y_staff)
{
   return set_measure(x_measure, y_staff, nullptr);
}



bool MeasureGrid::in_grid_range(int x_measure, int y_staff)
{
   if (x_measure < 0 || x_measure >= this->get_num_measures() || this->get_num_measures() == 0) return false;
   if (y_staff < 0 || y_staff >= this->get_num_staves() || this->get_num_staves() == 0) return false;

   return true;
}



int MeasureGrid::get_num_measures() const
{
   if (voices.empty()) return 0;
   return voices[0]->measures.size();
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
      // TODO: IMPORTANT here we are depending on voices[0] to currectly
      // report the current number of measures
      int num_measures = (voices.empty()) ? 8 : voices[0]->measures.size();
      voices.insert(voices.begin() + index, new Row(num_measures));
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
   // TODO: IMPORTANT here we are depending on voices[0] to currectly
   // report the current number of measures
   int num_measures = (voices.empty()) ? 8 : voices[0]->measures.size();
   voices.push_back(new Row(num_measures));
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
         // number of measures (they likely may not once there are different "staff" types)
         // TODO: this method is "constructing" the voice.  Probably should not
         // be doing this here
         voices[i]->measures.insert(voices[i]->measures.begin() + index, nullptr);
      }
   }
}



bool MeasureGrid::delete_column(int index)
{
   int num_measures = get_num_measures();

   if (index < 0 || index >= num_measures) return false;

   // remove the time signature
   time_signatures.erase(time_signatures.begin() + index);

   // remove the measure from each row
   // WARNING: this assumes voices have "measures" to remove, also
   // is assuming the role of being responsible for deleting contents
   // inside another class
   // This should likely be replaced with a voice[i]->delete_measure(int) function
   for (unsigned i=0; i<voices.size(); i++)
      voices[i]->measures.erase(voices[i]->measures.begin() + index);

   return true;
}



void MeasureGrid::append_measure()
{
   // append time signature
   time_signatures.push_back(TimeSignature(4, Duration()));

   // append measure to each row
   for (unsigned i=0; i<voices.size(); i++)
   {
      // warning, this is responsible for constructing the measures
      // that are appended.  This should likely be replaced by a
      // Voice::append_column();
      voices[i]->measures.push_back(nullptr);
   }
}



bool MeasureGrid::set_voice_name(int row_number, std::string name)
{
   if (row_number < 0) return "";
   if (row_number >= voices.size()) return "";
   voices[row_number]->name = name;
   return true;
}



std::string MeasureGrid::get_voice_name(int row_number)
{
   if (row_number < 0) return "";
   if (row_number >= voices.size()) return "";
   return voices[row_number]->name;
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



TimeSignature *MeasureGrid::get_time_signature_ptr(int index)
{
   if (index < 0 || index >= get_num_measures()) return nullptr;

   return &time_signatures[index];
}



