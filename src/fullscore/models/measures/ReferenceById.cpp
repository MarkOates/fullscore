


#include <fullscore/models/measures/ReferenceById.hpp>

#include <fullscore/models/Repositories/MeasureRepository.hpp>



Measure::ReferenceByID::ReferenceByID(int measure_id)
   : Base(MeasureRepository::TYPE_IDENTIFIER_REFERENCE_BY_ID)
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
   return MeasureRepository::find(measure_id);
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



