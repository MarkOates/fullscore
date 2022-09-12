#pragma once


#include <fullscore/actions/Base.h>


class AppController;

namespace UI::GridEditor::Actions
{
   class CreateNewPlotterEditor : public Action::Base
   {
   private:
      AppController *app_controller;

   public:
      CreateNewPlotterEditor(AppController *app_controller);
      ~CreateNewPlotterEditor();

      bool execute() override;
   };
};


