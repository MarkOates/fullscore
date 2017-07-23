#pragma once



#include <fullscore/actions/action_base.h>



class AppController;
class GUIScoreEditor;

namespace Action
{
   class SetCurrentGUIScoreEditor : public Base
   {
   private:
      AppController *app_controller;
      GUIScoreEditor *gui_score_editor;

   public:
      SetCurrentGUIScoreEditor(AppController *app_controller, GUIScoreEditor *gui_score_editor);
      ~SetCurrentGUIScoreEditor();

      bool execute() override;
   };
};




