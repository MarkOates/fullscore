



#include <fullscore/UI/GridEditor/Actions/SetCommandMode.hpp>

#include <fullscore/AppController.hpp>


namespace UI::GridEditor::Actions
{


SetCommandMode::SetCommandMode(UIGridEditor *grid_editor, UICommandBar *command_bar)
   : ::Action::Base("set_command_mode")
   , grid_editor(grid_editor)
   , command_bar(command_bar)
{
}




SetCommandMode::~SetCommandMode()
{
}




bool SetCommandMode::execute()
{
   if (!grid_editor)
      throw std::invalid_argument("Cannot set grid_editor to COMMAND_MODE because the grid_editor is a nullptr");
   if (!command_bar)
      throw std::invalid_argument("Cannot set grid_editor to COMMAND_MODE because the command_bar is a nullptr");
   if (grid_editor->mode == UIGridEditor::COMMAND_MODE)
      throw std::invalid_argument("Cannot set grid_editor to COMMAND_MODE because it is already in COMMAND_MODE, skipping.");

   //command_bar->text_input->set_as_focused();
   grid_editor->mode = UIGridEditor::COMMAND_MODE;

   return true;
}


} // namespace UI::GridEditor::Actions


