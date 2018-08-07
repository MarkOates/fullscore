#pragma once


#include <fullscore/actions/Base.h>
#include <string>


namespace UI::AppNavigator { class Widget; }


namespace UI::AppNavigator
{
   class ActionFactory
   {
   public:
      static Action::Base *create_action(UI::AppNavigator::Widget *widget, std::string action_name);
   };
}


