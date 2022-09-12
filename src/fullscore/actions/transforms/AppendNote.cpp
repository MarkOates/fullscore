


#include <fullscore/actions/transforms/AppendNote.hpp>

#include <fullscore/transforms/AppendNoteTransform.hpp>



Action::Transform::AppendNote::AppendNote(std::vector<Note> *notes, Note note)
   : Base("append_note")
   , notes(notes)
   , note(note)
{}



Action::Transform::AppendNote::~AppendNote()
{}



bool Action::Transform::AppendNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot append_note to nullptr notes");

   ::Transform::AppendNote append_note_transform(note);
   *notes = append_note_transform.transform(*notes);

   return true;
}



