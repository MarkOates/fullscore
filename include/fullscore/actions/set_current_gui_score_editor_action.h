#pragma once



#include <fullscore/actions/action_base.h>



class FullscoreApplicationController;
class GUIScoreEditor;

namespace Action
{
   class SetCurrentGUIScoreEditor : public Base
   {
   private:
      FullscoreApplicationController *app_controller;
      GUIScoreEditor *gui_score_editor;

   public:
      SetCurrentGUIScoreEditor(FullscoreApplicationController *app_controller, GUIScoreEditor *gui_score_editor);
      ~SetCurrentGUIScoreEditor();

      bool execute() override;
   };
};




