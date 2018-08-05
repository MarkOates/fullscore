



#include <fullscore/UI/GridEditor/Actions/SetCameraTarget.hpp>

#include <fullscore/widgets/FollowCamera.h>


namespace UI::GridEditor::Actions
{



SetCameraTarget::SetCameraTarget(UIFollowCamera *camera, float x, float y)
   : ::Action::Base("set_camera_target")
   , camera(camera)
   , x(x)
   , y(y)
{}




SetCameraTarget::~SetCameraTarget()
{}




bool SetCameraTarget::execute()
{
   if (!camera) return false;

   camera->target.position.x = x;
   camera->target.position.y = y;

   return true;
}


} // namespace UI::GridEditor::Actions


