



#include <fullscore/actions/transforms/insert_note_action.h>

#include <fullscore/transforms/insert_note_transform.h>




Action::InsertNoteTransform::InsertNoteTransform(std::vector<Note> *notes, int at_index, Note note)
   : Base("insert_note")
   , notes(notes)
   , at_index(at_index)
   , note(note)
{}




Action::InsertNoteTransform::~InsertNoteTransform()
{}




bool Action::InsertNoteTransform::execute()
{
   if (!notes || notes->empty() || at_index < 0 || at_index >= notes->size()) return false;

   ::Transform::InsertNote insert_note_transform(at_index, note);
   *notes = insert_note_transform.transform(*notes);

   return true;
}




