



#include <fullscore/helpers/measure_grid_helper.h>

#include <fullscore/helpers/duration_helper.h>
#include <fullscore/models/measure_grid.h>




float MeasureGridHelper::get_length_to_measure(const MeasureGrid &measure_grid, int measure_index)
{
   if (measure_index < 0) return 0.0;

   measure_index = std::min((int)measure_grid.time_signatures.size(), measure_index);

   float length = 0;
   for (unsigned i=0; i<measure_index; i++)
      length += DurationHelper::get_length(measure_grid.time_signatures[i]);

   return length;
}




