#pragma once




#include <fullscore/actions/action_base.h>




class Measure;

namespace Action
{
   class PasteMeasureFromBuffer : public Base
   {
   private:
      Measure *yank_measure_buffer;
      Measure *destination_measure;

   public:
      PasteMeasureFromBuffer(Measure *destination_measure, Measure *yank_measure_buffer);
      ~PasteMeasureFromBuffer();

      bool execute();
   };
}




