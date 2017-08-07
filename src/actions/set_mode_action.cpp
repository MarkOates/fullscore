



#include <fullscore/actions/set_mode_action.h>

#include <fullscore/app_controller.h>



Action::SetMode::SetMode(UIGridEditor *grid_editor, UICommandBar *command_bar, UIGridEditor::mode_t mode)
   : Base("set_mode")
   , grid_editor(grid_editor)
   , command_bar(command_bar)
   , mode(mode)
{
}




Action::SetMode::~SetMode()
{
}




bool Action::SetMode::execute()
{
   if (!grid_editor || !command_bar) return false;
   if (mode == grid_editor->mode) return false;

   switch(mode)
   {
   case UIGridEditor::NORMAL_MODE:
      command_bar->text_input->set_as_unfocused();
      grid_editor->mode = UIGridEditor::NORMAL_MODE;
      break;
   case UIGridEditor::INSERT_MODE:
      grid_editor->mode = UIGridEditor::INSERT_MODE;
      break;
   case UIGridEditor::COMMAND_MODE:
      command_bar->text_input->set_as_focused();
      grid_editor->mode = UIGridEditor::COMMAND_MODE;
      break;
   default:
      return false;
      break;
   }

   return true;
}




