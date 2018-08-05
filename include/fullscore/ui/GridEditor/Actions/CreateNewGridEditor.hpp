#pragma once



#include <fullscore/actions/Base.h>



class AppController;

namespace UI::GridEditor::Actions
{
   class CreateNewScoreEditor : public Action::Base
   {
   private:
      AppController *app_controller;

   public:
      CreateNewScoreEditor(AppController *app_controller);
      ~CreateNewScoreEditor();

      bool execute() override;
   };
};



