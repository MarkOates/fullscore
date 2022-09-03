


#include <fullscore/models/measures/Basic.hpp>

#include <fullscore/models/Repositories/MeasureRepository.hpp>
#include <fullscore/models/Note.hpp>



Measure::Basic::Basic(std::vector<Note> notes)
   : Base(Measure::TYPE_IDENTIFIER_BASIC)
   , notes(notes)
   , extension(12)
{
   // TODO remove this on initialization, move to constructor
   //set_notes(notes);
}



bool Measure::Basic::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
   return true;
}



int Measure::Basic::get_num_notes()
{
   return notes.size();
}



std::vector<Note> Measure::Basic::get_notes_copy()
{
   return notes;
}



std::vector<Note> *Measure::Basic::get_notes_pointer()
{
   return &notes;
}



