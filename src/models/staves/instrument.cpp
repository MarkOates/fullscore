


#include <fullscore/models/staves/instrument.h>

#include <fullscore/models/measures/base.h>



Staff::Instrument::Instrument(int num_columns)
   : Base("instrument")
   , columns()
{
   for (unsigned i=0; i<num_columns; i++) columns.push_back(nullptr);
}



Staff::Instrument::~Instrument()
{
   if (!columns.empty())
      for (int i=columns.size()-1; i>=0; i--)
         delete columns[i];
}



int Staff::Instrument::get_num_columns()
{
   return columns.size();
}



float Staff::Instrument::get_height()
{
   return 1.0;
}



bool Staff::Instrument::set_column(int column_num, Measure::Base *measure)
{
   if (column_num < 0) return false;
   if (column_num >= columns.size()) return false;

   if (columns[column_num]) delete columns[column_num];

   columns[column_num] = measure;
   return true;
}



bool Staff::Instrument::insert_column(int at_index, Measure::Base *measure)
{
   if (at_index < 0) return false;
   if (at_index >= columns.size()) return false;

   columns.insert(columns.begin() + at_index, measure);
   return true;
}



bool Staff::Instrument::erase_column(int at_index)
{
   if (at_index < 0) std::runtime_error("Cannot erase measure < 0");
   if (at_index >= columns.size()) std::runtime_error("Cannot erase measure >= size()");

   if (columns[at_index]) delete columns[at_index];

   columns.erase(columns.begin() + at_index);

   return true;
}



bool Staff::Instrument::append_column(Measure::Base *measure)
{
   columns.push_back(measure);
   return true;
}



Measure::Base *Staff::Instrument::get_measure(int column_num)
{
   if (column_num < 0 || column_num >= get_num_columns()) return nullptr;
   return columns[column_num];
}



