


#include <fullscore/models/staves/tempo.h>

#include <fullscore/models/measures/base.h>



Staff::Tempo::TempoMarkingCoordinate::TempoMarkingCoordinate(int measure_number, float position, TempoMarking tempo_marking)
   : measure_number(measure_number)
   , position(position)
   , tempo_marking(tempo_marking)
{}



Staff::Tempo::Tempo(int num_columns)
   : Base("tempo")
{}



Staff::Tempo::~Tempo()
{}



bool Staff::Tempo::set_tempo_marking(int measure_number, float position, TempoMarking marking)
{
   markings.push_back(TempoMarkingCoordinate(measure_number, position, marking));
   return true;
}



bool Staff::Tempo::set_column(int column_num, Measure::Base *measure)
{
   throw std::runtime_error("Cannot set a measure on a Tempo column");
}



bool Staff::Tempo::insert_column(int at_index, Measure::Base *measure)
{
   return true;
}



bool Staff::Tempo::erase_column(int at_index)
{
   return true;
}



bool Staff::Tempo::append_column(Measure::Base *measure)
{
   return true;
}



Measure::Base *Staff::Tempo::get_measure(int column_num)
{
   return nullptr;
}



int Staff::Tempo::get_num_columns()
{
   return 0;
}



float Staff::Tempo::get_height()
{
   return 0.5;
}



