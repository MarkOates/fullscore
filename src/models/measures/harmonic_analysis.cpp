


#include <fullscore/models/staves/harmonic_analysis.h>

#include <fullscore/models/measures/base.h>



Staff::HarmonicAnalysis::HarmonicAnalysis(int num_columns)
   : Base("harmonic_analysis")
   , num_columns(num_columns)
{}



Staff::HarmonicAnalysis::~HarmonicAnalysis()
{}



bool Staff::HarmonicAnalysis::set_column(int column_num, Measure::Base *measure)
{
   throw std::runtime_error("Cannot set a measure on a HarmonicAnalysis column");
}



bool Staff::HarmonicAnalysis::insert_column(int at_index, Measure::Base *measure)
{
   num_columns++;
   return true;
}



bool Staff::HarmonicAnalysis::erase_column(int at_index)
{
   if (at_index < 0 || at_index >= num_columns) return false;
   num_columns--;
   return true;
}



bool Staff::HarmonicAnalysis::append_column(Measure::Base *measure)
{
   num_columns++;
   return true;
}



Measure::Base *Staff::HarmonicAnalysis::get_measure(int column_num)
{
   return nullptr;
}



int Staff::HarmonicAnalysis::get_num_columns()
{
   return num_columns;
}



float Staff::HarmonicAnalysis::get_height()
{
   return 0.9;
}



