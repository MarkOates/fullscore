



#include <fullscore/UI/GridEditor/Actions/SetScoreZoom.hpp>

#include <fullscore/widgets/GridEditor.h>
#include <allegro_flare/motion.h>



Action::SetScoreZoom::SetScoreZoom(UIGridEditor *grid_editor, Motion *motion, float destination, float duration)
   : ::Action::Base("set_score_zoom")
   , grid_editor(grid_editor)
   , motion(motion)
   , destination(destination)
   , duration(duration)
{}




Action::SetScoreZoom::~SetScoreZoom()
{}




bool Action::SetScoreZoom::execute()
{
   if (!grid_editor || !motion) return false;

   motion->cmove_to(&grid_editor->place.scale.x, destination, duration);
   motion->cmove_to(&grid_editor->place.scale.y, destination, duration);

   return true;
}




