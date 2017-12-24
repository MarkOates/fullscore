


#include <fullscore/models/staves/Tempo.h>

#include <fullscore/models/measures/Base.h>



Staff::Tempo::TempoMarkingCoordinate::TempoMarkingCoordinate(int measure_number, float position, TempoMarking tempo_marking)
   : measure_number(measure_number)
   , position(position)
   , tempo_marking(tempo_marking)
{}



Staff::Tempo::Tempo()
   : Base("tempo")
   , markings()
{}



Staff::Tempo::~Tempo()
{}



bool Staff::Tempo::set_tempo_marking(int measure_number, float position, TempoMarking marking)
{
   if (position < 0.0 || position > 1.0) throw std::invalid_argument("Setting a tempo marking to be > 1 or < 0 is not allowed");
   markings.push_back(TempoMarkingCoordinate(measure_number, position, marking));
   return true;
}



std::vector<std::pair<TempoMarking, float>> Staff::Tempo::get_tempo_markings_in_measure(int measure_number)
{
   std::vector<std::pair<TempoMarking, float>> result = {};

   for (unsigned i=0; i<markings.size(); i++)
      if (markings[i].measure_number == measure_number)
         result.push_back(std::pair<TempoMarking, float>(markings[i].tempo_marking, markings[i].position));

   return result;
}



float Staff::Tempo::get_height()
{
   return 0.5;
}



