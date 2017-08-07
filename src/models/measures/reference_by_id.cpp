


#include <fullscore/models/measures/reference_by_id.h>

#include <fullscore/models/measure.h>



Measure::ReferenceByID::ReferenceByID(int measure_id)
   : Base(Measure::TYPE_IDENTIFIER_REFERENCE_BY_ID)
   , measure_id(measure_id)
{}



std::vector<Note> Measure::ReferenceByID::get_notes_copy()
{
   Measure::Base *measure = get_referenced_measure();
   if (measure) return measure->get_notes_copy();
   return {};
}



Measure::Base *Measure::ReferenceByID::get_referenced_measure()
{
   return Measure::find(measure_id);
}



int Measure::ReferenceByID::get_num_notes()
{
   Measure::Base *measure = get_referenced_measure();
   if (!measure) return 0;
   return measure->get_num_notes();
}



bool Measure::ReferenceByID::set_notes(std::vector<Note> notes)
{
   return false;
}



std::vector<Note> *Measure::ReferenceByID::get_notes_pointer()
{
   return nullptr; //TODO ensure all calls to get_notes_pointer() check for validity
}



