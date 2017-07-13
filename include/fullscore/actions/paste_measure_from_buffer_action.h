#pragma once




#include <fullscore/actions/action_base.h>




class BasicMeasure;

namespace Action
{
   class PasteMeasureFromBuffer : public Base
   {
   private:
      BasicMeasure *yank_measure_buffer;
      BasicMeasure *destination_measure;

   public:
      PasteMeasureFromBuffer(BasicMeasure *destination_measure, BasicMeasure *yank_measure_buffer);
      ~PasteMeasureFromBuffer();

      bool execute();
   };
}




