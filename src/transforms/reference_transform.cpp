


#include <fullscore/transforms/reference_transform.h>

#include <fullscore/models/measure_grid.h>
#include <sstream>



Transform::Reference::Reference(MeasureGrid *measure_grid, int source_x, int source_y)
   : Base("reference")
   , measure_grid(measure_grid)
   , source_x(source_x)
   , source_y(source_y)
{}



std::vector<Note> Transform::Reference::transform(std::vector<Note> n)
{
   if (!measure_grid) throw std::runtime_error("cannot reference measure from empty measure_grid");

   Measure::Base *measure = measure_grid->get_measure(source_x, source_y);

   if (!measure)
   {
      std::stringstream error_message;
      error_message << "measure does not exist at (" << source_x << ", " << source_y << ")" << std::endl;
      throw std::runtime_error(error_message.str());
   }

   return measure->get_notes_copy();
}



