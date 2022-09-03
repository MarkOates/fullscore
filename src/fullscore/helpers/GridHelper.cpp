



#include <fullscore/helpers/GridDimensionsHelper.hpp>

#include <fullscore/models/staves/Base.hpp>
#include <fullscore/helpers/DurationHelper.hpp>
#include <fullscore/models/Grid.hpp>




float GridDimensionsHelper::get_length_to_measure(const Grid &grid, int measure_index)
{
   if (measure_index < 0) return 0.0;

   measure_index = std::min((int)grid.time_signatures.size(), measure_index);

   float length = 0;
   for (unsigned i=0; i<measure_index; i++)
      length += DurationHelper::get_length(grid.time_signatures[i]);

   return length;
}




float GridDimensionsHelper::get_width(const Grid &grid)
{
   float length = 0;
   for (unsigned i=0; i<grid.time_signatures.size(); i++)
      length += DurationHelper::get_length(grid.time_signatures[i]);
   return length;
}




float GridDimensionsHelper::get_height_to_staff(const Grid &grid, int staff_index)
{
   if (staff_index < 0) return 0.0;
   if (staff_index >= grid.get_num_staves()) return grid.get_height();

   float height = 0;
   for (unsigned i=0; i<staff_index; i++)
   {
      Staff::Base *staff = grid.voices[i];
      if (!staff) throw std::runtime_error("Cannot get_height_to_staff with a nullptr staff");
      height += staff->get_height();
   }

   return height;
}




float GridDimensionsHelper::get_height_of_staff(Grid &grid, int staff_index) // TODO make const
{
   Staff::Base *staff = grid.get_staff(staff_index);
   if (!staff) return 0.0;
   return staff->get_height();
}




