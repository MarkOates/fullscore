


#include <fullscore/models/staves/instrument.h>

#include <fullscore/models/measures/base.h>
#include <fullscore/models/measure.h>



Staff::Instrument::Instrument(int num_columns)
   : Base("instrument")
   //, columns()
   , columns_of_measure_ids()
{
   //for (unsigned i=0; i<num_columns; i++) columns.push_back(nullptr);
   for (unsigned i=0; i<num_columns; i++) columns_of_measure_ids.push_back(Measure::NO_RECORD);
}



Staff::Instrument::~Instrument()
{
   //if (!columns.empty())
      //for (int i=columns.size()-1; i>=0; i--)
         //delete columns[i];
}



int Staff::Instrument::get_num_columns()
{
   return columns_of_measure_ids.size();
}



float Staff::Instrument::get_height()
{
   return 1.0;
}



bool Staff::Instrument::set_column(int column_num, Measure::Base *measure)
{
   if (column_num < 0) return false;
   if (column_num >= columns_of_measure_ids.size()) return false;

   int measure_id_to_write = Measure::NO_RECORD;
   if (measure) measure_id_to_write = measure->get_id();

   //if (columns[column_num]) delete columns[column_num];

   columns_of_measure_ids[column_num] = measure_id_to_write;
   return true;
}



bool Staff::Instrument::insert_column(int at_index, Measure::Base *measure)
{
   if (at_index < 0) return false;
   if (at_index >= columns_of_measure_ids.size()) return false;

   int measure_id_to_write = Measure::NO_RECORD;
   if (measure) measure_id_to_write = measure->get_id();

   columns_of_measure_ids.insert(columns_of_measure_ids.begin() + at_index, measure_id_to_write);
   return true;
}



bool Staff::Instrument::erase_column(int at_index)
{
   if (at_index < 0) std::runtime_error("Cannot erase measure < 0");
   if (at_index >= columns_of_measure_ids.size()) std::runtime_error("Cannot erase measure >= size()");

   //if (columns[at_index]) delete columns[at_index];

   columns_of_measure_ids.erase(columns_of_measure_ids.begin() + at_index);

   return true;
}



bool Staff::Instrument::append_column(Measure::Base *measure)
{
   int measure_id_to_write = Measure::NO_RECORD;
   if (measure) measure_id_to_write = measure->get_id();

   columns_of_measure_ids.push_back(measure_id_to_write);
   return true;
}



Measure::Base *Staff::Instrument::get_measure(int column_num)
{
   if (column_num < 0 || column_num >= get_num_columns()) return nullptr;

   Measure::Base *found_measure = Measure::find(columns_of_measure_ids[column_num]);

   //return columns[column_num];
   return found_measure;
}



