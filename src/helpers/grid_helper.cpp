



#include <fullscore/helpers/measure_grid_helper.h>

#include <fullscore/models/staves/base.h>
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




float MeasureGridHelper::get_width(const MeasureGrid &measure_grid)
{
   float length = 0;
   for (unsigned i=0; i<measure_grid.time_signatures.size(); i++)
      length += DurationHelper::get_length(measure_grid.time_signatures[i]);
   return length;
}




float MeasureGridHelper::get_height_to_staff(const MeasureGrid &measure_grid, int staff_index)
{
   if (staff_index < 0) return 0.0;
   if (staff_index >= measure_grid.get_num_staves()) return measure_grid.get_height();

   float height = 0;
   for (unsigned i=0; i<staff_index; i++)
   {
      Staff::Base *staff = measure_grid.voices[i];
      if (!staff) throw std::runtime_error("Cannot get_height_to_staff with a nullptr staff");
      height += staff->get_height();
   }

   return height;
}




float MeasureGridHelper::get_height_of_staff(MeasureGrid &measure_grid, int staff_index) // TODO make const
{
   Staff::Base *staff = measure_grid.get_staff(staff_index);
   if (!staff) return 0.0;
   return staff->get_height();
}




