



#include <fullscore/actions/set_current_grid_editor_action.h>

#include <fullscore/app_controller.h>
#include <fullscore/widgets/grid_editor.h>



Action::SetCurrentUIGridEditor::SetCurrentUIGridEditor(AppController *app_controller, UIGridEditor *grid_editor)
   : Base("set_current_grid_editor")
   , app_controller(app_controller)
   , grid_editor(grid_editor)
{}




Action::SetCurrentUIGridEditor::~SetCurrentUIGridEditor()
{}




bool Action::SetCurrentUIGridEditor::execute()
{
   if (!app_controller || !grid_editor) return false;

   return app_controller->set_current_grid_editor(grid_editor);
}




