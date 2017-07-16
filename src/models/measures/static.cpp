


#include <fullscore/models/measures/static.h>



Measure::Static::Static()
   : Base("static")
{}



std::vector<Note> Measure::Static::get_notes_copy()
{
   return { Note(0), Note(2), Note(4), Note(5), Note(7), Note(9), Note(11) };
}



bool Measure::Static::set_notes(std::vector<Note> notes)
{
   return false;
}



std::vector<Note> *Measure::Static::get_notes_pointer()
{
   return nullptr;
}



