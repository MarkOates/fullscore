



#include <fullscore/actions/toggle_command_bar_action.h>

#include <fullscore/command_bar.h>




Action::ToggleCommandBar::ToggleCommandBar(UICommandBar *command_bar)
   : Base("toggle_command_bar")
   , command_bar(command_bar)
{
}




Action::ToggleCommandBar::~ToggleCommandBar()
{
}




bool Action::ToggleCommandBar::execute()
{
   if (!command_bar) return false;

   if (command_bar->text_input->is_focused()) command_bar->text_input->set_as_unfocused();
   else command_bar->text_input->set_as_focused();
   return true;
}




