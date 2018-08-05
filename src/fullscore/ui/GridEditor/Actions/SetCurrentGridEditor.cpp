



#include <fullscore/UI/GridEditor/Actions/SetCurrentGridEditor.hpp>

#include <fullscore/AppController.hpp>
#include <fullscore/UI/GridEditor/Widget.hpp>
//#include <fullscore/widgets/GridEditor.h>


namespace UI::GridEditor::Actions
{


SetCurrentUIGridEditor::SetCurrentUIGridEditor(AppController *app_controller, UI::GridEditor::Widget *grid_editor)
   : ::Action::Base("set_current_grid_editor")
   , app_controller(app_controller)
   , grid_editor(grid_editor)
{}




SetCurrentUIGridEditor::~SetCurrentUIGridEditor()
{}




bool SetCurrentUIGridEditor::execute()
{
   if (!app_controller || !grid_editor) return false;

   return app_controller->set_current_grid_editor_widget(grid_editor);
}


} // namespace UI::GridEditor::Actions


