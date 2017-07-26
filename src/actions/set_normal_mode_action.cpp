



#include <fullscore/actions/set_normal_mode_action.h>

#include <fullscore/app_controller.h>



Action::SetNormalMode::SetNormalMode(UIMeasureGridEditor *score_editor, UICommandBar *command_bar)
   : Base("set_normal_mode")
   , score_editor(score_editor)
   , command_bar(command_bar)
{
}




Action::SetNormalMode::~SetNormalMode()
{
}




bool Action::SetNormalMode::execute()
{
   if (!score_editor || !command_bar) return false;
   if (score_editor->mode == UIMeasureGridEditor::NORMAL_MODE) return false;

   command_bar->text_input->set_as_unfocused();
   score_editor->mode = UIMeasureGridEditor::NORMAL_MODE;

   return true;
}




