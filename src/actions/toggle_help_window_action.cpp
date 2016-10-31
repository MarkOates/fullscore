



#include <fullscore/actions/toggle_help_window_action.h>

#include <fullscore/fullscore_application_controller.h>




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

   placement2d *place = &fullscore_application_controller->help_window->place;

   if (fullscore_application_controller->showing_help_menu)
   {
      // hide the help menu
      motion->cmove_to(&place->position.x, -600, 0.4);
      motion->cmove_to(&place->position.y, -100, 0.4);
      motion->cmove_to(&place->rotation, -0.1, 0.4);
      fullscore_application_controller->showing_help_menu = false;
   }
   else
   {
      // show the help menu
      motion->cmove_to(&place->position.x, fullscore_application_controller->display->center(), 0.4);
      motion->cmove_to(&place->position.y, fullscore_application_controller->display->middle(), 0.4);
      motion->cmove_to(&place->rotation, 0, 0.4);
      fullscore_application_controller->showing_help_menu = true;
   }

   return false;
}




