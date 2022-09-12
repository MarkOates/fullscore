#pragma once


#include <fullscore/actions/Base.h>
#include <string>


namespace UI::PlotterEditor { class Widget; }


namespace UI::PlotterEditor
{
   class ActionFactory
   {
   public:
      static Action::Base *create_action(UI::PlotterEditor::Widget *widget, std::string action_name);
   };
}


