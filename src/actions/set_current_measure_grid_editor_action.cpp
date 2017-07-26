



#include <fullscore/actions/set_current_measure_grid_editor_action.h>

#include <fullscore/app_controller.h>
#include <fullscore/widgets/measure_grid_editor.h>



Action::SetCurrentUIMeasureGridEditor::SetCurrentUIMeasureGridEditor(AppController *app_controller, UIMeasureGridEditor *measure_grid_editor)
   : Base("set_current_measure_grid_editor")
   , app_controller(app_controller)
   , measure_grid_editor(measure_grid_editor)
{}




Action::SetCurrentUIMeasureGridEditor::~SetCurrentUIMeasureGridEditor()
{}




bool Action::SetCurrentUIMeasureGridEditor::execute()
{
   if (!app_controller || !measure_grid_editor) return false;

   return app_controller->set_current_measure_grid_editor(measure_grid_editor);
}




