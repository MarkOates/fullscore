



#include <fullscore/actions/set_current_gui_score_editor_action.h>

#include <fullscore/app_controller.h>
#include <fullscore/widgets/gui_score_editor.h>



Action::SetCurrentUIMeasureGridEditor::SetCurrentUIMeasureGridEditor(AppController *app_controller, UIMeasureGridEditor *gui_score_editor)
   : Base("set_current_gui_score_editor")
   , app_controller(app_controller)
   , gui_score_editor(gui_score_editor)
{}




Action::SetCurrentUIMeasureGridEditor::~SetCurrentUIMeasureGridEditor()
{}




bool Action::SetCurrentUIMeasureGridEditor::execute()
{
   if (!app_controller || !gui_score_editor) return false;

   return app_controller->set_current_gui_score_editor(gui_score_editor);
}




