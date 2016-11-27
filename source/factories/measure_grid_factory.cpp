


#include <fullscore/factories/measure_grid_factory.h>
#include <fullscore/models/note.h>
#include <fullscore/models/measure.h>



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
   measure_grid.get_measure(1,0)->notes.push_back(Note(4, 2));

   measure_grid.get_measure(2,0)->notes.push_back(Note(0+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(0+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(-1+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(-1+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-2+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-2+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-3+3, 2));

   return measure_grid;
}



