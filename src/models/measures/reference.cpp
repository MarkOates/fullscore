


#include <fullscore/models/measures/reference.h>
#include <fullscore/models/measure_grid.h>



Measure::Reference::Reference(MeasureGrid *measure_grid, int measure_x, int staff_y)
   : Base("reference")
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



std::vector<Note> Measure::Reference::get_notes_copy()
{
   // TODO: this could be a dead pointer if it is deleted externally
   Measure::Base *referenced_measure = measure_grid->get_measure(measure_x, staff_y);
   if (referenced_measure) referenced_measure->get_notes_copy();
   return {};
}



Measure::Base *Measure::Reference::get_referenced_measure()
{
   return measure_grid->get_measure(measure_x, staff_y);
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
   return nullptr;
}



