


#include <fullscore/transforms/AppendNoteTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transform::AppendNote::AppendNote(Note note)
   : Base(TransformNames::APPEND_NOTE_TRANSFORM_IDENTIFIER)
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



