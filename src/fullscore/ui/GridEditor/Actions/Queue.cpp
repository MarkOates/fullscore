



#include <fullscore/UI/GridEditor/Actions/Queue.hpp>



namespace UI::GridEditor::Actions
{


Queue::Queue(std::string name, std::vector<Action::Base *> actions)
   : ::Action::Base(std::string("queue: (") + name + ")")
   , actions(actions)
{
}




Queue::~Queue()
{
   clear();
}




bool Queue::add_action(::Action::Base *action)
{
   actions.push_back(action);
   return true;
}




bool Queue::execute()
{
   bool status = true;
   for (auto &action : actions)
      if (!action->execute()) status = false;
   return status;
}




bool Queue::clear()
{
   for (auto &action : actions) delete action;
   actions.clear();
   return true;
}


} // namespace UI::GridEditor::Actions


