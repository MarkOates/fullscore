


#include <fullscore/transforms/AppendNoteTransform.hpp>

#include <fullscore/Transform.h>



Transform::AppendNote::AppendNote(Note note)
   : Base(Transform::APPEND_NOTE_TRANSFORM_IDENTIFIER)
   , note(note)
{
}



Transform::AppendNote::~AppendNote()
{
}



std::vector<Note> Transform::AppendNote::transform(std::vector<Note> notes)
{
   notes.push_back(note);
   return notes;
}



