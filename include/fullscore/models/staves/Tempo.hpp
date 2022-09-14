#pragma once



#include <fullscore/models/staves/Base.hpp>

#include <fullscore/models/TempoMarking.hpp>



namespace Staff
{
   class Tempo : public Base
   {
   private:
      class TempoMarkingCoordinate
      {
      public:
         int measure_number;
         float position;
         TempoMarking tempo_marking;

         TempoMarkingCoordinate(int measure_number, float position, TempoMarking tempo_marking);
      };

      std::vector<TempoMarkingCoordinate> markings;

   public:
      Tempo();
      ~Tempo();

      virtual float get_height() override;

      bool set_tempo_marking(int measure_number, float position, TempoMarking marking);
      std::vector<std::pair<TempoMarking, float>> get_tempo_markings_in_measure(int measure_number);
   };
};



