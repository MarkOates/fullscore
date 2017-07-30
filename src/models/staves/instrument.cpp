


#include <fullscore/models/staves/instrument.h>

#include <fullscore/models/measures/base.h>



Staff::Instrument::Instrument(int num_columns)
   : Base("instrument")
{
   for (unsigned i=0; i<num_columns; i++) measures.push_back(nullptr);
}



Staff::Instrument::~Instrument()
{
   // TODO erase all the measures here
}



bool Staff::Instrument::set_column(int column_num, Measure::Base *measure)
{
   // TODO move the bounds check to be handled in here
   // TODO if there is already a measure present, the deletion should be moved to here as well
   measures[column_num] = measure;
   return true;
}



bool Staff::Instrument::insert_column(int at_index, Measure::Base *measure)
{
   // TODO move the bounds check to here
   // behavior that < 0 inserts are corrected to 0 and
   // >= size measures default to append() should probably be handled
   // at the MeasureGrid layer, since it would need to be implement in
   // all of the derived classes, and is expected behavior of the MeasureGrid
   measures.insert(measures.begin() + at_index, measure);
   return true;
}



bool Staff::Instrument::erase_column(int at_index)
{
   // TODO move the bounds check to here
   // behavior that < 0 inserts are corrected to 0 and

   // >= size measures default to append() should probably be handled
   // at the MeasureGrid layer, since it would need to be implement in
   // all of the derived classes, and is expected behavior of the MeasureGrid
   if (at_index < 0) std::runtime_error("Cannot erase measure < 0");
   if (at_index >= measures.size()) std::runtime_error("Cannot erase measure >= size()");

   if (measures[at_index]) delete measures[at_index];

   measures.erase(measures.begin() + at_index);

   return true;
}



bool Staff::Instrument::append_column(Measure::Base *measure)
{
   measures.push_back(measure);
   return true;
}



Measure::Base *Staff::Instrument::get_measure(int column_num)
{
   if (column_num < 0 || column_num >= get_num_columns()) return nullptr;
   return measures[column_num];
}



