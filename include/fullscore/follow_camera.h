#pragma once




#include <allegro_flare/gui/widgets/camera.h>




class UIFollowCamera : public UICamera
{
public:
   placement2d target;

   UIFollowCamera(UIWidget *parent);
   ~UIFollowCamera();

   void primary_timer_func();
};



