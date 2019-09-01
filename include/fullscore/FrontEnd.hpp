#pragma once


#include <allegro_flare/display.h>
#include <allegro_flare/gui/gui_screen.h>


namespace fullscore
{
   class FrontEnd : private UIScreen
   {
   private:
      Display* display;

   public:
      FrontEnd(Display* display=nullptr);
      ~FrontEnd();


   void on_timer_func() override;
   };
}



