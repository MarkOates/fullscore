#pragma once




#include <fullscore/actions/action_base.h>




namespace Measure { class Basic; }

namespace Action
{
   class PasteMeasureFromBuffer : public Base
   {
   private:
      Measure::Basic *yank_measure_buffer;
      Measure::Basic *destination_measure;

   public:
      PasteMeasureFromBuffer(Measure::Basic *destination_measure, Measure::Basic *yank_measure_buffer);
      ~PasteMeasureFromBuffer();

      bool execute();
   };
}




