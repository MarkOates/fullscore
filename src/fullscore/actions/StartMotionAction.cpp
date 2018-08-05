



#include <fullscore/actions/StartMotionAction.h>

#include <allegro_flare/motion.h>
#include <fullscore/Action.h>




Action::StartMotion::StartMotion(Motion *motion, float *value, float destination, float duration)
   : Base(Action::START_MOTION_ACTION_IDENTIFIER)
   , motion(motion)
   , value(value)
   , destination(destination)
   , duration(duration)
{}




Action::StartMotion::~StartMotion()
{}




bool Action::StartMotion::execute()
{
   if (!motion || !value) return false;

   motion->cmove(value, destination-*value, duration);

   return true;
}



