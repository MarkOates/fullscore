



#include <iostream>
#include <vector>
#include <string>
#include <allegro5/allegro.h>



int main(int argv, char **argc)
{
   std::vector<std::string> args;
   for (int i=0; i<argv; i++) args.push_back(argc[i]);

   if (!al_init()) std::cerr << "al_init() failed" << std::endl;
   ALLEGRO_PATH *resource_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
   al_change_directory(al_path_cstr(resource_path, ALLEGRO_NATIVE_PATH_SEP));
   al_destroy_path(resource_path);

   std::cout << "WORKING!" << std::endl;
   return 0;
}




