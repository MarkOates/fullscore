#pragma once



#include <fullscore/actions/base.h>



namespace Measure { class Basic; class Base; }

namespace Action
{
   class YankGridMeasureToBuffer : public Base
   {
   private:
      Measure::Basic *yank_measure_buffer;
      Measure::Base *source_measure;

   public:
      YankGridMeasureToBuffer(Measure::Basic *yank_measure_buffer, Measure::Base *source_measure);
      ~YankGridMeasureToBuffer();

      bool execute();
   };
}



