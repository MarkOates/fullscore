#pragma once


#include <fullscore/actions/Base.h>
#include <string>


namespace UI::ComponentTemplate { class Widget; }


namespace UI::ComponentTemplate
{
   class ActionFactory
   {
   public:
      static Action::Base *create_action(UI::ComponentTemplate::Widget *widget, std::string action_name);
   };
}


