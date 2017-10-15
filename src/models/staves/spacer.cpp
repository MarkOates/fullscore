


#include <fullscore/models/staves/spacer.h>

#include <fullscore/models/measures/base.h>



Staff::Spacer::Spacer(int num_columns)
   : Base("spacer")
{}



Staff::Spacer::~Spacer()
{}



bool Staff::Spacer::set_column(int column_num, Measure::Base *measure)
{
   throw std::runtime_error("Cannot set a measure on a Spacer column");
}



bool Staff::Spacer::insert_column(int at_index, Measure::Base *measure)
{
   return true;
}



bool Staff::Spacer::erase_column(int at_index)
{
   return true;
}



bool Staff::Spacer::append_column(Measure::Base *measure)
{
   return true;
}



Measure::Base *Staff::Spacer::get_measure(int column_num)
{
   return nullptr;
}



int Staff::Spacer::get_num_columns()
{
   return 0;
}



float Staff::Spacer::get_height()
{
   return 0.5;
}



