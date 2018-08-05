



#include <fullscore/UI/GridEditor/Actions/SetCameraTarget.hpp>

#include <fullscore/widgets/FollowCamera.h>




Action::SetCameraTarget::SetCameraTarget(UIFollowCamera *camera, float x, float y)
   : ::Action::Base("set_camera_target")
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




