


#include <fullscore/models/measures/reference_by_coordinate.h>

#include <fullscore/models/measure.h>
#include <fullscore/models/grid.h>



Measure::ReferenceByCoordinate::ReferenceByCoordinate(Grid *referenced_grid, int referenced_measure_x, int referenced_staff_y)
   : Base(Measure::TYPE_IDENTIFIER_REFERENCE_BY_COORDINATE)
   , referenced_grid(referenced_grid)
   , referenced_measure_x(referenced_measure_x)
   , referenced_staff_y(referenced_staff_y)
{}



std::vector<Note> Measure::ReferenceByCoordinate::get_notes_copy()
{
   if (!referenced_grid) return {};

   // TODO: this could be a dead pointer if it is deleted externally
   Measure::Base *referenced_measure = referenced_grid->get_measure(referenced_measure_x, referenced_staff_y);
   if (referenced_measure) return referenced_measure->get_notes_copy();
   return {};
}



Measure::Base *Measure::ReferenceByCoordinate::get_referenced_measure()
{
   if (!referenced_grid) return nullptr;

   return referenced_grid->get_measure(referenced_measure_x, referenced_staff_y);
}



int Measure::ReferenceByCoordinate::get_num_notes()
{
   Measure::Base *measure = get_referenced_measure();
   if (!measure) return 0;
   return measure->get_num_notes();
}



bool Measure::ReferenceByCoordinate::set_notes(std::vector<Note> notes)
{
   return false;
}



std::vector<Note> *Measure::ReferenceByCoordinate::get_notes_pointer()
{
   return nullptr; //TODO ensure all calls to get_notes_pointer() check for validity
}



