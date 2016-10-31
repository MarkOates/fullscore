#pragma once




#include <fullscore/actions/action_base.h>




class Motion;
class FullscoreApplicationController;

namespace Action
{
   class ToggleHelpWindow : public Base
   {
   private:
      Motion *motion;
      FullscoreApplicationController *fullscore_application_controller;

   public:
      ToggleHelpWindow(Motion *motion, FullscoreApplicationController *fullscore_application_controller);
      ~ToggleHelpWindow();

      bool execute() override;
   };
};




