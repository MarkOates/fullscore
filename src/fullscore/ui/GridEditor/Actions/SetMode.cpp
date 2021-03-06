



#include <fullscore/UI/GridEditor/Actions/SetMode.hpp>

#include <fullscore/widgets/CommandBar.h>
#include <fullscore/AppController.hpp>


namespace UI::GridEditor::Actions
{


SetMode::SetMode(UIGridEditor *grid_editor, UICommandBar *command_bar, UIGridEditor::mode_t mode)
   : ::Action::Base("set_mode")
   , grid_editor(grid_editor)
   , command_bar(command_bar)
   , mode(mode)
{
}




SetMode::~SetMode()
{
}




bool SetMode::execute()
{
   if (!grid_editor || !command_bar) return false;
   if (mode == grid_editor->mode) return false;

   switch(mode)
   {
   case UIGridEditor::NORMAL_MODE:
      command_bar->text_input->set_as_unfocused();
      grid_editor->mode = UIGridEditor::NORMAL_MODE;
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


} // namespace UI::GridEditor::Actions


