


#include <fullscore/models/NoteSet.h>



NoteSet::NoteSet(std::vector<Note> notes)
   : notes(notes)
{}



std::vector<Note> NoteSet::get_notes()
{
   return notes;
}



std::vector<Note> &NoteSet::get_notes_ref()
{
   return notes;
}



bool NoteSet::operator==(const NoteSet &other) const
{
   return other.notes == notes;
}



