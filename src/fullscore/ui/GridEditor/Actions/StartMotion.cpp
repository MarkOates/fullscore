



#include <fullscore/UI/GridEditor/Actions/StartMotion.hpp>

#include <allegro_flare/motion.h>
#include <fullscore/UI/GridEditor/Actions.hpp>



namespace UI::GridEditor::Actions
{


StartMotion::StartMotion(Motion *motion, float *value, float destination, float duration)
   : ::Action::Base(START_MOTION_ACTION_IDENTIFIER)
   , motion(motion)
   , value(value)
   , destination(destination)
   , duration(duration)
{}




StartMotion::~StartMotion()
{}




bool StartMotion::execute()
{
   if (!motion || !value) return false;

   motion->cmove(value, destination-*value, duration);

   return true;
}


} // namespace UI::GridEditor::Actions


