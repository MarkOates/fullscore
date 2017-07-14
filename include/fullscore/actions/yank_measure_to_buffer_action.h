#pragma once




#include <fullscore/actions/action_base.h>




namespace Measure { class BasicMeasure; }

namespace Action
{
   class YankMeasureToBuffer : public Base
   {
   private:
      Measure::BasicMeasure *yank_measure_buffer;
      Measure::BasicMeasure *source_measure;

   public:
      YankMeasureToBuffer(Measure::BasicMeasure *yank_measure_buffer, Measure::BasicMeasure *source_measure);
      ~YankMeasureToBuffer();

      bool execute();
   };
}




