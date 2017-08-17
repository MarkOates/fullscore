#pragma once



#include <string>



namespace Action { class Base; }
class AppController;

class ActionFactory
{
public:
   static Action::Base *create_action(AppController *app_controller, std::string action_identifier);
};



