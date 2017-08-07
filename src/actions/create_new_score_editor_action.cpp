



#include <fullscore/actions/create_new_score_editor_action.h>

#include <fullscore/factories/grid_factory.h>
#include <fullscore/app_controller.h>




Action::CreateNewScoreEditor::CreateNewScoreEditor(AppController *app_controller)
   : Base("create_new_score_editor")
   , app_controller(app_controller)
{}




Action::CreateNewScoreEditor::~CreateNewScoreEditor()
{}




bool Action::CreateNewScoreEditor::execute()
{
   if (!app_controller) return false;

   app_controller->create_new_score_editor("");

   return true;
}




