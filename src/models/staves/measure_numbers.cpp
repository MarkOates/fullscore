


#include <fullscore/models/staves/measure_numbers.h>

#include <fullscore/models/measures/base.h>



Staff::MeasureNumbers::MeasureNumbers(int num_columns)
   : Base("measure_numbers")
   , num_columns(num_columns)
{}



Staff::MeasureNumbers::~MeasureNumbers()
{}



bool Staff::MeasureNumbers::set_column(int column_num, Measure::Base *measure)
{
   throw std::runtime_error("Cannot set a measure on a MeasureNumbers column");
}



bool Staff::MeasureNumbers::insert_column(int at_index, Measure::Base *measure)
{
   return true;
}



bool Staff::MeasureNumbers::erase_column(int at_index)
{
   return true;
}



bool Staff::MeasureNumbers::append_column(Measure::Base *measure)
{
   return true;
}



Measure::Base *Staff::MeasureNumbers::get_measure(int column_num)
{
   return nullptr;
}



int Staff::MeasureNumbers::get_num_columns()
{
   return num_columns;
}



float Staff::MeasureNumbers::get_height()
{
   return 0.75;
}



