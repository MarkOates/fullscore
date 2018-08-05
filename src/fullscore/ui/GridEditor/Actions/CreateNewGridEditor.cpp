



#include <fullscore/UI/GridEditor/Actions/CreateNewGridEditor.hpp>

#include <fullscore/factories/GridFactory.h>
#include <fullscore/AppController.hpp>


namespace UI::GridEditor::Actions
{



CreateNewScoreEditor::CreateNewScoreEditor(AppController *app_controller)
   : ::Action::Base("create_new_grid_editor")
   , app_controller(app_controller)
{}




CreateNewScoreEditor::~CreateNewScoreEditor()
{}




bool CreateNewScoreEditor::execute()
{
   if (!app_controller) return false;

   app_controller->create_new_grid_editor("");

   return true;
}


} // namespace UI::GridEditor::Actions


