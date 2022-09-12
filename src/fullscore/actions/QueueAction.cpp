



#include <fullscore/actions/QueueAction.hpp>




Action::Queue::Queue(std::string name, std::vector<Action::Base *> actions)
   : Base(std::string("queue: (") + name + ")")
   , actions(actions)
{
}




Action::Queue::~Queue()
{
   clear();
}




bool Action::Queue::add_action(Action::Base *action)
{
   actions.push_back(action);
   return true;
}




bool Action::Queue::execute()
{
   bool status = true;
   for (auto &action : actions)
      if (!action->execute()) status = false;
   return status;
}




bool Action::Queue::clear()
{
   for (auto &action : actions) delete action;
   actions.clear();
   return true;
}




