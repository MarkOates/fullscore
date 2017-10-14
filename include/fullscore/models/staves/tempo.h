#pragma once



#include <fullscore/models/staves/base.h>

#include <fullscore/models/tempo_marking.hpp>



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
      Tempo(int num_columns);
      ~Tempo();

      virtual int get_num_columns() override;
      virtual float get_height() override;

      virtual Measure::Base *get_measure(int column_num) override;
      std::vector<Measure::Base *> get_measures_in(int column_num) override;
      virtual bool set_column(int column_num, Measure::Base *measure) override;
      virtual bool insert_column(int at_index, Measure::Base *measure) override;
      virtual bool erase_column(int at_index) override;
      virtual bool append_column(Measure::Base *measure) override;

      bool set_tempo_marking(int measure_number, float position, TempoMarking marking);
      std::vector<std::pair<TempoMarking, float>> get_tempo_markings_in_measure(int measure_number);
   };
};



