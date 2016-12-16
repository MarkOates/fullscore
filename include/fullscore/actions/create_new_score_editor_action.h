#pragma once




#include <fullscore/actions/action_base.h>




class FullscoreApplicationController;

namespace Action
{
   class CreateNewScoreEditor : public Base
   {
   private:
      FullscoreApplicationController *app_controller;

   public:
      CreateNewScoreEditor(FullscoreApplicationController *app_controller);
      ~CreateNewScoreEditor();

      bool execute() override;
   };
};




