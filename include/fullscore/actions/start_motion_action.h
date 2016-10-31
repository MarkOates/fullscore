#pragma once




#include <fullscore/actions/action_base.h>




namespace Action
{
   class StartMotion : public Base
   {
   public:
      StartMotion();
      ~StartMotion();

      bool execute() override;
   };
};




