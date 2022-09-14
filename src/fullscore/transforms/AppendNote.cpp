


#include <fullscore/Transforms/AppendNote.hpp>

#include <fullscore/TransformNames.hpp>



Transforms::AppendNote::AppendNote(Note note)
   : Base(TransformNames::APPEND_NOTE_TRANSFORM_IDENTIFIER)
   , note(note)
{
}



Transforms::AppendNote::~AppendNote()
{
}



std::vector<Note> Transforms::AppendNote::transform(std::vector<Note> notes)
{
   notes.push_back(note);
   return notes;
}



