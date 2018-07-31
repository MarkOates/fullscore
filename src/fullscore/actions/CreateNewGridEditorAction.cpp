



#include <fullscore/actions/CreateNewGridEditorAction.h>

#include <fullscore/factories/GridFactory.h>
#include <fullscore/AppController.h>




Action::CreateNewScoreEditor::CreateNewScoreEditor(AppController *app_controller)
   : Base("create_new_grid_editor")
   , app_controller(app_controller)
{}




Action::CreateNewScoreEditor::~CreateNewScoreEditor()
{}




bool Action::CreateNewScoreEditor::execute()
{
   if (!app_controller) return false;

   app_controller->create_new_grid_editor("");

   return true;
}




