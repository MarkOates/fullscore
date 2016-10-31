#pragma once




#include <fullscore/actions/action_base.h>




namespace Action
{
   class ToggleHelpWindow : public Base
   {
   public:
      ToggleHelpWindow();
      ~ToggleHelpWindow();

      bool execute() override;
   };
};




