


#include <fullscore/models/measures/reference.h>

#include <fullscore/models/measure.h>
#include <fullscore/models/grid.h>



Measure::Reference::Reference(Grid *grid, int measure_x, int staff_y)
   : Base(Measure::TYPE_IDENTIFIER_REFERENCE)
   , grid(grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



std::vector<Note> Measure::Reference::get_notes_copy()
{
   if (!grid) return {};

   // TODO: this could be a dead pointer if it is deleted externally
   Measure::Base *referenced_measure = grid->get_measure(measure_x, staff_y);
   if (referenced_measure) return referenced_measure->get_notes_copy();
   return {};
}



Measure::Base *Measure::Reference::get_referenced_measure()
{
   if (!grid) return nullptr;

   return grid->get_measure(measure_x, staff_y);
}



int Measure::Reference::get_num_notes()
{
   Measure::Base *measure = get_referenced_measure();
   if (!measure) return 0;
   return measure->get_num_notes();
}



bool Measure::Reference::set_notes(std::vector<Note> notes)
{
   return false;
}



std::vector<Note> *Measure::Reference::get_notes_pointer()
{
   return nullptr; //TODO ensure all calls to get_notes_pointer() check for validity
}



