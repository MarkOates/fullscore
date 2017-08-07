


#include <fullscore/actions/transforms/append_note_action.h>

#include <fullscore/transforms/append_note_transform.h>



Action::Transform::AppendNote::AppendNote(std::vector<Note> *notes, Note note)
   : Base("append_note")
   , notes(notes)
   , note(note)
{}



Action::Transform::AppendNote::~AppendNote()
{}



bool Action::Transform::AppendNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot append note to NULL notes");

   ::Transform::AppendNote append_note_transform(note);
   *notes = append_note_transform.transform(*notes);

   return true;
}



