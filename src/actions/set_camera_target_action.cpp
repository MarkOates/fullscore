



#include <fullscore/actions/set_camera_target_action.h>

#include <fullscore/follow_camera.h>




Action::SetCameraTarget::SetCameraTarget(UIFollowCamera *camera, float x, float y)
   : Base("set_camera_target")
   , camera(camera)
   , x(x)
   , y(y)
{}




Action::SetCameraTarget::~SetCameraTarget()
{}




bool Action::SetCameraTarget::execute()
{
   if (!camera) return false;

   camera->target.position.x = x;
   camera->target.position.y = y;

   return true;
}




