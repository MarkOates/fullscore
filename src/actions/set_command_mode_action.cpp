



#include <fullscore/actions/set_command_mode_action.h>

#include <fullscore/app_controller.h>



Action::SetCommandMode::SetCommandMode(UIGridEditor *score_editor, UICommandBar *command_bar)
   : Base("set_command_mode")
   , score_editor(score_editor)
   , command_bar(command_bar)
{
}




Action::SetCommandMode::~SetCommandMode()
{
}




bool Action::SetCommandMode::execute()
{
   if (!score_editor)
      throw std::invalid_argument("Cannot set score_editor to COMMAND_MODE because the score_editor is a nullptr");
   if (!command_bar)
      throw std::invalid_argument("Cannot set score_editor to COMMAND_MODE because the command_bar is a nullptr");
   if (score_editor->mode == UIGridEditor::COMMAND_MODE)
      throw std::invalid_argument("Cannot set score_editor to COMMAND_MODE because it is already in COMMAND_MODE, skipping.");

   command_bar->text_input->set_as_focused();
   score_editor->mode = UIGridEditor::COMMAND_MODE;

   return true;
}




