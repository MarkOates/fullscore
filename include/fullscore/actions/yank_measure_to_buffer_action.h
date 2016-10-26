#pragma once




#include <fullscore/actions/action_base.h>




class Measure;

namespace Action
{
   class YankMeasureToBufferAction : public Base
   {
   private:
      Measure *yank_measure_buffer;
      Measure *source_measure;

   public:
      YankMeasureToBufferAction(Measure *yank_measure_buffer, Measure *source_measure);
      ~YankMeasureToBufferAction();

      bool execute();
   };
}




