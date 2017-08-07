


#include <fullscore/actions/transforms/append_note_action.h>

#include <fullscore/transforms/append_note_transform.h>



Action::Transform::AppendNoteTransform::AppendNoteTransform(std::vector<Note> *notes, Note note)
   : Base("append_note")
   , notes(notes)
   , note(note)
{}



Action::Transform::AppendNoteTransform::~AppendNoteTransform()
{}



bool Action::Transform::AppendNoteTransform::execute()
{
   if (!notes) throw std::runtime_error("Cannot append note to NULL notes");

   ::Transform::AppendNote append_note_transform(note);
   *notes = append_note_transform.transform(*notes);

   return true;
}



