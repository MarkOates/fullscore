



#include <fullscore/actions/set_normal_mode_action.h>

#include <fullscore/app_controller.h>



Action::SetNormalMode::SetNormalMode(UIGridEditor *grid_editor, UICommandBar *command_bar)
   : Base("set_normal_mode")
   , grid_editor(grid_editor)
   , command_bar(command_bar)
{
}




Action::SetNormalMode::~SetNormalMode()
{
}




bool Action::SetNormalMode::execute()
{
   if (!grid_editor)
      throw std::invalid_argument("Cannot set grid_editor to NORMAL_MODE because the grid_editor is a nullptr");
   if (!command_bar)
      throw std::invalid_argument("Cannot set grid_editor to NORMAL_MODE because the command_bar is a nullptr");
   if (grid_editor->mode == UIGridEditor::NORMAL_MODE)
      throw std::invalid_argument("Cannot set grid_editor to NORMAL_MODE because it is already in NORMAL_MODE, skipping.");

   command_bar->text_input->set_as_unfocused();
   grid_editor->mode = UIGridEditor::NORMAL_MODE;

   return true;
}




