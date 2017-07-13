#pragma once




#include <fullscore/actions/action_base.h>




class BasicMeasure;

namespace Action
{
   class YankMeasureToBuffer : public Base
   {
   private:
      BasicMeasure *yank_measure_buffer;
      BasicMeasure *source_measure;

   public:
      YankMeasureToBuffer(BasicMeasure *yank_measure_buffer, BasicMeasure *source_measure);
      ~YankMeasureToBuffer();

      bool execute();
   };
}




