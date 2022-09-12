


#include <allegro_flare/allegro_flare.h>

#include <fullscore/FrontEnd.hpp>


using namespace fullscore;


int main(int argc, char *argv[])
{
   Framework::initialize();
   Config config = Framework::get_config();
   Display *d = Framework::create_display(
         config.get_or_default_int("GLOBAL_SETTINGS", "resolution_x", 800),
         config.get_or_default_int("GLOBAL_SETTINGS", "resolution_y", 600)
      );
   FrontEnd front_end(d);
   Framework::run_loop();

   return 0;
}



