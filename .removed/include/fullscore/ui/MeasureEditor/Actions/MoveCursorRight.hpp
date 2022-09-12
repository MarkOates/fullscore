#pragma once


#include <fullscore/actions/Base.h>


namespace UI::MeasureEditor { class Widget; }

namespace UI::MeasureEditor::Actions
{
   class MoveCursorRight : public Action::Base
   {
   private:
      UI::MeasureEditor::Widget *widget;

   public:
      MoveCursorRight(UI::MeasureEditor::Widget *widget);
      ~MoveCursorRight();

      bool execute() override;
   };
}


