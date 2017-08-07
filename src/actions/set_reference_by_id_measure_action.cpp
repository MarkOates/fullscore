


#include <fullscore/actions/set_reference_by_id_measure_action.h>

#include <fullscore/models/measures/reference_by_id.h>
#include <fullscore/models/grid.h>



Action::SetReferenceByIDMeasure::SetReferenceByIDMeasure(Grid *destination_grid, int destination_measure_x, int destination_staff_y, int referenced_measure_id)
   : Base("set_reference_by_id_measure")
   , destination_grid(destination_grid)
   , destination_measure_x(destination_measure_x)
   , destination_staff_y(destination_staff_y)
   , referenced_measure_id(referenced_measure_id)
{}



Action::SetReferenceByIDMeasure::~SetReferenceByIDMeasure()
{}



bool Action::SetReferenceByIDMeasure::execute()
{
   if (!destination_grid) throw std::runtime_error("Cannot set Measure::ReferenceByID on a nullptr destination_grid");

   // TODO validations that a measure is not referencing itself

   Measure::ReferenceByID *new_referenced_measure = new Measure::ReferenceByID(referenced_measure_id);

   bool measure_set_successfully = destination_grid->set_measure(destination_measure_x, destination_staff_y, new_referenced_measure);

   if (!measure_set_successfully)
   {
      delete new_referenced_measure;
      std::stringstream error_message;
      error_message << "Could not set a Measure::ReferenceByID the measure in the destination_grid at (" << destination_measure_x << ", " << destination_staff_y << ")";
      throw std::runtime_error(error_message.str());
   }

   return true;
}



