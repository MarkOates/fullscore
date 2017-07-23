



#include <allegro_flare/allegro_flare.h>

#include <fullscore/app_controller.h>




int main(int argc, char *argv[])
{
   Framework::initialize();
   Display *d = Framework::create_display(1920, 1080);
   AppController *app = new AppController(d);
   Framework::run_loop();

   return 0;
}




