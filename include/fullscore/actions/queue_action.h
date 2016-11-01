#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>

namespace Action
{
   class Queue : public Base
   {
   private:
      std::vector<Action::Base *> actions;

   public:
      Queue(std::string name, std::vector<Action::Base *> actions = {});
      ~Queue();

      bool execute() override;

      bool add_action(Action::Base *action);
      bool clear();
   };
};




