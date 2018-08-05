#pragma once


#include <string>


namespace UI::GridEditor { class Widget; }
namespace Action { class Base; }


namespace UI::GridEditor
{
   class ActionFactory
   {
   public:
      static Action::Base *create_action(UI::GridEditor::Widget *widget, std::string action_name);
   };
}


