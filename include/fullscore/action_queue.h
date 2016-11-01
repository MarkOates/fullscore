#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>

class ActionQueue
{
private:
   std::vector<Action::Base *> actions;

public:
   ActionQueue();
   ~ActionQueue();

   void add_action(Action::Base *action);
   bool invoke_all();
};




