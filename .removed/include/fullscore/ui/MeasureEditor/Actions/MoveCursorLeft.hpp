#pragma once


#include <fullscore/actions/Base.h>


namespace UI::MeasureEditor { class Widget; }

namespace UI::MeasureEditor::Actions
{
   class MoveCursorLeft : public Action::Base
   {
   private:
      UI::MeasureEditor::Widget *widget;

   public:
      MoveCursorLeft(UI::MeasureEditor::Widget *widget);
      ~MoveCursorLeft();

      bool execute() override;
   };
}


