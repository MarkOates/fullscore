


#include <fullscore/transforms/copy.h>

#include <fullscore/models/measure_grid.h>
#include <sstream>



Transform::Copy::Copy(MeasureGrid *measure_grid, int source_x, int source_y)
   : Base("copy")
   , measure_grid(measure_grid)
   , source_x(source_x)
   , source_y(source_y)
{}



std::vector<Note> Transform::Copy::transform(std::vector<Note> n)
{
   if (!measure_grid) throw std::runtime_error("cannot copy measure from empty measure_grid");

   Measure::BasicMeasure *measure = measure_grid->get_measure(source_x, source_y);

   if (!measure)
   {
      std::stringstream error_message;
      error_message << "measure does not exist at (" << source_x << ", " << source_y << ")" << std::endl;
      throw std::runtime_error(error_message.str());
   }

   return measure->get_notes_copy();
}



