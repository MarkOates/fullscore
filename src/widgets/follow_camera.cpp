



#include <fullscore/widgets/follow_camera.h>

#include <cmath>




UIFollowCamera::UIFollowCamera(UIWidget *parent)
   : UICamera(parent, 0, 0, 1, 1)
{}




UIFollowCamera::~UIFollowCamera()
{}




void UIFollowCamera::on_timer()
{
   const float THRESHOLD = 0.01;
   const float REDUCTION_PERCENT = 0.2;

   if (place.position.x != target.position.x)
   {
      place.position.x = (target.position.x - place.position.x) * REDUCTION_PERCENT + place.position.x;
      if (fabs(target.position.x - place.position.x) <= THRESHOLD)
         place.position.x = target.position.x;
   }

   if (place.position.y != target.position.y)
   {
      place.position.y = (target.position.y - place.position.y) * REDUCTION_PERCENT + place.position.y;
      if (fabs(target.position.y - place.position.y) <= THRESHOLD)
         place.position.y = target.position.y;
   }

   if (place.scale.x != target.scale.x)
   {
      place.scale.x = (target.scale.x - place.scale.x) * REDUCTION_PERCENT + place.scale.x;
      if (fabs(target.scale.x - place.scale.x) <= THRESHOLD)
         place.scale.x = target.scale.x;
   }

   if (place.scale.y != target.scale.y)
   {
      place.scale.y = (target.scale.y - place.scale.y) * REDUCTION_PERCENT + place.scale.y;
      if (fabs(target.scale.y - place.scale.y) <= THRESHOLD)
         place.scale.y = target.scale.y;
   }
};




void UIFollowCamera::on_draw() {}
