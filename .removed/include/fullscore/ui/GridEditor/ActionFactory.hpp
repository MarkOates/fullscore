#pragma once


#include <string>


namespace UI::GridEditor { class Widget; }
namespace Action { class Base; }
class AppController;


namespace UI::GridEditor
{
   class ActionFactory
   {
   public:
      static Action::Base *create_action(AppController *app_controller, UI::GridEditor::Widget *widget, std::string action_name);
   };
}


