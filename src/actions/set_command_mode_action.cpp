



#include <fullscore/actions/set_command_mode_action.h>

#include <fullscore/app_controller.h>



Action::SetCommandMode::SetCommandMode(UIMeasureGridEditor *score_editor, UICommandBar *command_bar)
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
   if (!score_editor || !command_bar) return false;
   if (score_editor->mode == UIMeasureGridEditor::COMMAND_MODE) return false;

   command_bar->text_input->set_as_focused();
   score_editor->mode = UIMeasureGridEditor::COMMAND_MODE;

   return true;
}




