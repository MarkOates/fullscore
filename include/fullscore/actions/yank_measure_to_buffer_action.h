#pragma once




#include <fullscore/actions/action_base.h>




class Measure;

namespace Action
{
   class YankMeasureToBuffer : public Base
   {
   private:
      Measure *yank_measure_buffer;
      Measure *source_measure;

   public:
      YankMeasureToBuffer(Measure *yank_measure_buffer, Measure *source_measure);
      ~YankMeasureToBuffer();

      bool execute();
   };
}




