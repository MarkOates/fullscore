#pragma once




#include <fullscore/actions/action_base.h>




namespace Action
{
   class ToggleShowDebugData : public Base
   {
   public:
      ToggleShowDebugData();
      ~ToggleShowDebugData();

      bool execute() override;
   };
};




