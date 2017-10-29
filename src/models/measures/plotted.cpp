


#include <fullscore/models/measures/plotted.h>

#include <fullscore/models/measure.h>
#include <fullscore/models/Note.h>
#include <allegro_flare/useful.h>



Measure::Plotted::Plotted(std::vector<Note> notes)
   : Base(Measure::TYPE_IDENTIFIER_PLOTTED)
   , notes(notes)
{
}



Measure::Plotted::~Plotted()
{
}



bool Measure::Plotted::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
   return true;
}



int Measure::Plotted::get_num_notes()
{
   return notes.size();
}



std::vector<Note> Measure::Plotted::get_notes_copy()
{
   return notes;
}



std::vector<Note> *Measure::Plotted::get_notes_pointer()
{
   return nullptr;
}



