



#include <fullscore/actions/Transforms/InsertNote.hpp>

#include <fullscore/Transforms/InsertNoteTransform.hpp>



Action::Transforms::InsertNote::InsertNote(std::vector<Note> *notes, int at_index, Note note)
   : Base("insert_note")
   , notes(notes)
   , at_index(at_index)
   , note(note)
{}




Action::Transforms::InsertNote::~InsertNote()
{}




bool Action::Transforms::InsertNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot InsertNote NULL notes");

   ::Transforms::InsertNote insert_note_transform(at_index, note);
   *notes = insert_note_transform.transform(*notes);

   return true;
}




