#pragma once


#include <fullscore/actions/Base.h>


namespace UI::MeasureEditor { class Widget; }

namespace UI::MeasureEditor::Actions
{
   class ToggleEditMode : public ::Action::Base
   {
   private:
      UI::MeasureEditor::Widget *widget;

   public:
      ToggleEditMode(UI::MeasureEditor::Widget *widget);
      ~ToggleEditMode();

      bool execute() override;
   };
};


