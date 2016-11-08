



#include <fullscore/models/measure_grid.h>

#include <iostream>
#include <fullscore/constants.h>
#include <fullscore/models/note.h>




MeasureGrid::Row::Row(int num_measures) : measures()
{
   measures.resize(num_measures, Measure());
}




Measure &MeasureGrid::Row::operator[](unsigned int index)
{
   if (index >= measures.size()) std::cout << "measure index out of bounds" << std::endl;
   return measures[index];
}




MeasureGrid::MeasureGrid(int num_x_measures, int num_y_staves)
   : voices()
  , time_signatures()
{
   voices.resize(num_y_staves, Row(num_x_measures));
   time_signatures.resize(num_x_measures, TimeSignature(4, DURATION_QUARTER, 0));
}




Measure *MeasureGrid::get_measure(int x_measure, int y_staff)
{
   // bounds check
   if (x_measure < 0 || x_measure >= this->get_num_measures() || this->get_num_measures() == 0) return NULL;
   if (y_staff < 0 || y_staff >= this->get_num_staves() || this->get_num_staves() == 0) return NULL;

   return &voices[y_staff][x_measure];
}




int MeasureGrid::get_num_measures()
{
   if (voices.empty()) return 0;
   return voices[0].measures.size();
}




int MeasureGrid::get_num_staves()
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
      time_signatures.insert(time_signatures.begin() + index, TimeSignature(4, DURATION_QUARTER, 0));

      // insert a measure into each row
      for (unsigned i=0; i<voices.size(); i++)
      {
         // WARNING: this assumes all staves have the same
         // number of measures (they should)
         voices[i].measures.insert(voices[i].measures.begin() + index, Measure());
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
   time_signatures.push_back(TimeSignature(4, DURATION_QUARTER, 0));

   // append measure to each row
   for (unsigned i=0; i<voices.size(); i++)
   {
      voices[i].measures.push_back(Measure());
   }
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
   if (index < 0) return TimeSignature(0, 0, 0);
   if (index >= get_num_measures()) return TimeSignature(0, 0, 0);

   return time_signatures[index];
}



