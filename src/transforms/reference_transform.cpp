


#include <fullscore/transforms/reference_transform.h>

#include <fullscore/models/measures/base.h>
#include <fullscore/models/grid.h>
#include <sstream>



Transform::Reference::Reference(Grid *grid, int source_x, int source_y)
   : Base("reference")
   , grid(grid)
   , source_x(source_x)
   , source_y(source_y)
{}



std::vector<Note> Transform::Reference::transform(std::vector<Note> n)
{
   if (!grid) throw std::runtime_error("cannot reference measure from empty grid");

   Measure::Base *measure = grid->get_measure(source_x, source_y);

   if (!measure)
   {
      std::stringstream error_message;
      error_message << "measure does not exist at (" << source_x << ", " << source_y << ")" << std::endl;
      throw std::runtime_error(error_message.str());
   }

   return measure->get_notes_copy();
}



