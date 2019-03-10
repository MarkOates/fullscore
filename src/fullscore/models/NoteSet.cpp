


#include <fullscore/models/NoteSet.hpp>



NoteSet::NoteSet(std::vector<Note> notes)
   : notes(notes)
{}



bool NoteSet::operator==(const NoteSet &other) const
{
   return other.notes == notes;
}



