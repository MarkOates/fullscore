



#include <fullscore/actions/set_mode_action.h>

#include <fullscore/app_controller.h>



Action::SetMode::SetMode(UIMeasureGridEditor *score_editor, UICommandBar *command_bar, UIMeasureGridEditor::mode_t mode)
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
   case UIMeasureGridEditor::NORMAL_MODE:
      command_bar->text_input->set_as_unfocused();
      score_editor->mode = UIMeasureGridEditor::NORMAL_MODE;
      break;
   case UIMeasureGridEditor::INSERT_MODE:
      score_editor->mode = UIMeasureGridEditor::INSERT_MODE;
      break;
   case UIMeasureGridEditor::COMMAND_MODE:
      command_bar->text_input->set_as_focused();
      score_editor->mode = UIMeasureGridEditor::COMMAND_MODE;
      break;
   default:
      return false;
      break;
   }

   return true;
}




