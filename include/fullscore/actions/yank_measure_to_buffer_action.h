#pragma once




#include <fullscore/actions/action_base.h>




namespace Measure { class Basic; }

namespace Action
{
   class YankMeasureToBuffer : public Base
   {
   private:
      Measure::Basic *yank_measure_buffer;
      Measure::Basic *source_measure;

   public:
      YankMeasureToBuffer(Measure::Basic *yank_measure_buffer, Measure::Basic *source_measure);
      ~YankMeasureToBuffer();

      bool execute();
   };
}




