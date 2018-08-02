



#include <fullscore/actions/SetCurrentGridEditorAction.h>

#include <fullscore/AppController.hpp>
#include <fullscore/widgets/GridEditor.h>



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




