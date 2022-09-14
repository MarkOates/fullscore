



#include <fullscore/UI/GridEditor/Actions/CreateNewPlotterEditor.hpp>

#include <fullscore/UI/GridEditor/Actions.hpp>
#include <fullscore/factories/GridFactory.h>
#include <fullscore/AppController.hpp>


namespace UI::GridEditor::Actions
{



CreateNewPlotterEditor::CreateNewPlotterEditor(AppController *app_controller)
   : ::Action::Base(CREATE_NEW_PLOTTER_EDITOR_ACTION_IDENTIFIER)
   , app_controller(app_controller)
{}




CreateNewPlotterEditor::~CreateNewPlotterEditor()
{}




bool CreateNewPlotterEditor::execute()
{
   if (!app_controller) return false;

   throw std::runtime_error("CreateNewPlotterEditor not implemented");
   //app_controller->create_new_grid_editor("");

   return true;
}


} // namespace UI::GridEditor::Actions



