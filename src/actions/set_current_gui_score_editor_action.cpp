



#include <fullscore/actions/set_current_gui_score_editor_action.h>

#include <fullscore/app_controller.h>
#include <fullscore/gui_score_editor.h>



Action::SetCurrentGUIScoreEditor::SetCurrentGUIScoreEditor(FullscoreApplicationController *app_controller, GUIScoreEditor *gui_score_editor)
   : Base("set_current_gui_score_editor")
   , app_controller(app_controller)
   , gui_score_editor(gui_score_editor)
{}




Action::SetCurrentGUIScoreEditor::~SetCurrentGUIScoreEditor()
{}




bool Action::SetCurrentGUIScoreEditor::execute()
{
   if (!app_controller || !gui_score_editor) return false;

   return app_controller->set_current_gui_score_editor(gui_score_editor);
}




