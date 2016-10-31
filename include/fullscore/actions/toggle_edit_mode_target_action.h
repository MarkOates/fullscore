#pragma once




#include <fullscore/actions/action_base.h>




namespace Action
{
   class ToggleEditModeTarget : public Base
   {
   public:
      ToggleEditModeTarget();
      ~ToggleEditModeTarget();

      bool execute() override;
   };
};




