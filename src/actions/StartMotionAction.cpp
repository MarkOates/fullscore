



#include <fullscore/actions/StartMotionAction.h>

#include <allegro_flare/motion.h>




Action::StartMotion::StartMotion(Motion *motion, float *value, float destination, float duration)
   : Base("start_motion")
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




