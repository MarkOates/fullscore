



#include <fullscore/actions/set_score_zoom_action.h>

#include <fullscore/gui_score_editor.h>
#include <allegro_flare/motion.h>



Action::SetScoreZoom::SetScoreZoom(GUIScoreEditor *score_editor, Motion *motion, float destination, float duration)
   : Base("set_score_zoom")
   , score_editor(score_editor)
   , motion(motion)
   , destination(destination)
   , duration(duration)
{}




Action::SetScoreZoom::~SetScoreZoom()
{}




bool Action::SetScoreZoom::execute()
{
   if (!score_editor || !motion) return false;

   motion->cmove_to(&score_editor->place.scale.x, destination, duration);
   motion->cmove_to(&score_editor->place.scale.y, destination, duration);

   return true;
}




