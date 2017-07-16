#pragma once




#include <fullscore/actions/action_base.h>




namespace Measure { class Basic; class Base; }

namespace Action
{
   class PasteMeasureFromBuffer : public Base
   {
   private:
      Measure::Basic *yank_measure_buffer;
      Measure::Base *destination_measure;

   public:
      PasteMeasureFromBuffer(Measure::Base *destination_measure, Measure::Basic *yank_measure_buffer);
      ~PasteMeasureFromBuffer();

      bool execute();
   };
}




