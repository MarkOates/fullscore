#pragma once


#include <string>


namespace UI::PlotterList { class Widget; }
namespace Action { class Base; }


namespace UI::PlotterList
{
   class ActionFactory
   {
   public:
      static Action::Base *create_action(UI::PlotterList::Widget *widget, std::string action_name);
   };
}


