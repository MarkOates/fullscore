



#include <allegro_flare/allegro_flare.h>

#include <fullscore/fullscore_project_controller.h>




int main(int argc, char *argv[])
{
   Framework::initialize();
   Display *d = Framework::create_display(1920, 1080);
   FullscoreProjectController *proj = new FullscoreProjectController(d);
   Framework::run_loop();

   return 0;
}




