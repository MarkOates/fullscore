



#include <fullscore/actions/set_mode_action.h>

#include <fullscore/app_controller.h>



Action::SetMode::SetMode(UIGridEditor *score_editor, UICommandBar *command_bar, UIGridEditor::mode_t mode)
   : Base("set_mode")
   , score_editor(score_editor)
   , command_bar(command_bar)
   , mode(mode)
{
}




Action::SetMode::~SetMode()
{
}




bool Action::SetMode::execute()
{
   if (!score_editor || !command_bar) return false;
   if (mode == score_editor->mode) return false;

   switch(mode)
   {
   case UIGridEditor::NORMAL_MODE:
      command_bar->text_input->set_as_unfocused();
      score_editor->mode = UIGridEditor::NORMAL_MODE;
      break;
   case UIGridEditor::INSERT_MODE:
      score_editor->mode = UIGridEditor::INSERT_MODE;
      break;
   case UIGridEditor::COMMAND_MODE:
      command_bar->text_input->set_as_focused();
      score_editor->mode = UIGridEditor::COMMAND_MODE;
      break;
   default:
      return false;
      break;
   }

   return true;
}




