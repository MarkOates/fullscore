#pragma once




#include <fullscore/actions/action_base.h>




namespace Action
{
   class SetScoreZoom : public Base
   {
   public:
      SetScoreZoom();
      ~SetScoreZoom();

      bool execute() override;
   };
};




