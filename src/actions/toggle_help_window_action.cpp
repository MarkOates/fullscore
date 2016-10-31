



#include <fullscore/actions/toggle_help_window_action.h>





Action::ToggleHelpWindow::ToggleHelpWindow(Motion *motion, FullscoreApplicationController *fullscore_application_controller)
   : Base("toggle_help_window")
   , motion(motion)
   , fullscore_application_controller(fullscore_application_controller)
{}




Action::ToggleHelpWindow::~ToggleHelpWindow()
{}




bool Action::ToggleHelpWindow::execute()
{
   if (!motion || !fullscore_application_controller) return false;

   if (fullscore_application_controller->showing_help_menu)
   {
      // hide the help menu
   }
   else
   {
      // show the help menu
   }

   return false;
}




