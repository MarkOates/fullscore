#pragma once




#include <fullscore/action/action_base.h>




namespace Action
{
   class Template : public Base
   {
   public:
      Template();
      ~Template();

      bool execute() override;
   };
};




