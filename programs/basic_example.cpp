#include <allegro5/allegro.h>

#include <fullscore/models/Grid.hpp>
#include <fullscore/models/staves/Instrument.hpp>
#include <fullscore/factories/GridFactory.hpp>

int main(int argc, char** argv)
{
   Grid grid = GridFactory::full_score();
   Staff::Base *staff = grid.get_staff(2);

   std::cout << staff->get_name() << std::endl;

   return 0;
};

