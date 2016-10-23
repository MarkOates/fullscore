



#include <allegro_flare/allegro_flare.h>

#include <fullscore/fullscore_application_controller.h>




int main(int argc, char *argv[])
{
   Framework::initialize();
   Display *d = Framework::create_display(1920, 1080);
   FullscoreApplicationController *proj = new FullscoreApplicationController(d);
   Framework::run_loop();

   return 0;
}




