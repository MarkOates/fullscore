



#include <fullscore/actions/set_mode_action.h>

#include <fullscore/fullscore_application_controller.h>



Action::SetMode::SetMode(GUIScoreEditor *score_editor, UICommandBar *command_bar, GUIScoreEditor::mode_t mode)
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
   case GUIScoreEditor::NORMAL_MODE:
      command_bar->text_input->set_as_unfocused();
      score_editor->mode = GUIScoreEditor::NORMAL_MODE;
      break;
   case GUIScoreEditor::INSERT_MODE:
      score_editor->mode = GUIScoreEditor::INSERT_MODE;
      break;
   case GUIScoreEditor::COMMAND_MODE:
      command_bar->text_input->set_as_focused();
      score_editor->mode = GUIScoreEditor::COMMAND_MODE;
      break;
   default:
      return false;
      break;
   }

   return true;
}




