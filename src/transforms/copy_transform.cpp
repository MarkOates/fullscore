


#include <fullscore/transforms/copy_transform.h>

#include <fullscore/models/measures/base.h>
#include <fullscore/models/grid.h>
#include <sstream>



Transform::Copy::Copy(Grid *grid, int source_x, int source_y)
   : Base("copy")
   , grid(grid)
   , source_x(source_x)
   , source_y(source_y)
{}



std::vector<Note> Transform::Copy::transform(std::vector<Note> n)
{
   if (!grid) throw std::runtime_error("cannot copy measure from empty grid");

   Measure::Base *measure = grid->get_measure(source_x, source_y);

   if (!measure)
   {
      std::stringstream error_message;
      error_message << "measure does not exist at (" << source_x << ", " << source_y << ")" << std::endl;
      throw std::runtime_error(error_message.str());
   }

   return measure->get_notes_copy();
}



