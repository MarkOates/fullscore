#pragma once



#include <vector>
#include <fullscore/actions/Base.h>

namespace UI::GridEditor::Actions
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



