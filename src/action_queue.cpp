



#include <fullscore/action_queue.h>




ActionQueue::ActionQueue()
   : actions()
{
}




ActionQueue::~ActionQueue()
{
}




void ActionQueue::add_action(Action::Base *action)
{
   actions.push_back(action);
}




bool ActionQueue::invoke_all()
{
   bool status = true;
   for (auto &action : actions)
      if (!action->execute()) status = false;
   return status;
}




