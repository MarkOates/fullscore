#pragma once



#include <fullscore/actions/Base.h>



namespace Measure { class Basic; class Base; }

namespace UI::GridEditor::Actions
{
   class YankGridMeasureToBuffer : public ::Action::Base
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



