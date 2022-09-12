#pragma once


#include <fullscore/actions/Base.h>
#include <string>


namespace UI::MeasureEditor { class Widget; }


namespace UI::MeasureEditor
{
   class ActionFactory
   {
   public:
      static Action::Base *create_action(UI::MeasureEditor::Widget *widget, std::string action_name);
   };
}


