



#include <fullscore/actions/set_mode_action.h>

#include <fullscore/command_bar.h>




Action::SetMode::SetMode(UICommandBar *command_bar)
   : Base("set_mode")
   , command_bar(command_bar)
{
}




Action::SetMode::~SetMode()
{
}




bool Action::SetMode::execute()
{
   if (!command_bar) return false;

   if (command_bar->text_input->is_focused()) command_bar->text_input->set_as_unfocused();
   else command_bar->text_input->set_as_focused();
   return true;
}




