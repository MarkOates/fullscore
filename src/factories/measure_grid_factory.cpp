


#include <fullscore/factories/measure_grid_factory.h>
#include <fullscore/models/note.h>
#include <fullscore/models/measure.h>
#include <allegro_flare/useful.h>
#include <iostream>



MeasureGrid MeasureGridFactory::twinkle_twinkle_little_star()
{
   MeasureGrid measure_grid(4, 2);

   // twinkle twinkle, little star
   measure_grid.get_measure(0,0)->notes.push_back(Note(0));
   measure_grid.get_measure(0,0)->notes.push_back(Note(0));
   measure_grid.get_measure(0,0)->notes.push_back(Note(4));
   measure_grid.get_measure(0,0)->notes.push_back(Note(4));
   measure_grid.get_measure(1,0)->notes.push_back(Note(5));
   measure_grid.get_measure(1,0)->notes.push_back(Note(5));
   measure_grid.get_measure(1,0)->notes.push_back(Note(4, Duration::HALF));

   measure_grid.get_measure(2,0)->notes.push_back(Note(0+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(0+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(-1+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(-1+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-2+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-2+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-3+3, Duration::HALF));

   for (int i=0; i<measure_grid.get_num_staves(); i++)
      measure_grid.set_voice_name(i, tostring("Voice ") + tostring(i));

   return measure_grid;
}



MeasureGrid MeasureGridFactory::big_score()
{
   MeasureGrid measure_grid(60, 12);

   for (int i=0; i<measure_grid.get_num_staves(); i++)
      measure_grid.set_voice_name(i, tostring("Voice ") + tostring(i));

   return measure_grid;
}



MeasureGrid MeasureGridFactory::create(std::string identifier)
{
   if (identifier == "big_score") return big_score();
   if (identifier == "twinkle_twinkle") return twinkle_twinkle_little_star();

   std::cout << "Could not find score " << identifier << std::endl;
   return MeasureGrid(4, 1);
}



