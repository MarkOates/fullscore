


#include <fullscore/models/measures/Basic.h>

#include <fullscore/models/Measure.h>
#include <fullscore/models/Note.h>
#include <allegro_flare/useful.h>



Measure::Basic::Basic(std::vector<Note> notes)
   : Base(Measure::TYPE_IDENTIFIER_BASIC)
   , notes()
   , extension(12)
{
   set_notes(notes);
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



