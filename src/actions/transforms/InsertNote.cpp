



#include <fullscore/actions/transforms/InsertNote.h>

#include <fullscore/transforms/InsertNoteTransform.h>



Action::Transform::InsertNote::InsertNote(std::vector<Note> *notes, int at_index, Note note)
   : Base("insert_note")
   , notes(notes)
   , at_index(at_index)
   , note(note)
{}




Action::Transform::InsertNote::~InsertNote()
{}




bool Action::Transform::InsertNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot InsertNote NULL notes");

   ::Transform::InsertNote insert_note_transform(at_index, note);
   *notes = insert_note_transform.transform(*notes);

   return true;
}




