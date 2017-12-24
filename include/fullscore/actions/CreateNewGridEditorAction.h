#pragma once



#include <fullscore/actions/Base.h>



class AppController;

namespace Action
{
   class CreateNewScoreEditor : public Base
   {
   private:
      AppController *app_controller;

   public:
      CreateNewScoreEditor(AppController *app_controller);
      ~CreateNewScoreEditor();

      bool execute() override;
   };
};



