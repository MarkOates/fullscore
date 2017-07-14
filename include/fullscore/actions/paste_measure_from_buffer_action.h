#pragma once




#include <fullscore/actions/action_base.h>




namespace Measure { class BasicMeasure; }

namespace Action
{
   class PasteMeasureFromBuffer : public Base
   {
   private:
      Measure::BasicMeasure *yank_measure_buffer;
      Measure::BasicMeasure *destination_measure;

   public:
      PasteMeasureFromBuffer(Measure::BasicMeasure *destination_measure, Measure::BasicMeasure *yank_measure_buffer);
      ~PasteMeasureFromBuffer();

      bool execute();
   };
}




