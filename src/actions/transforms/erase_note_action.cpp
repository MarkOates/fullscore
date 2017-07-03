



#include <fullscore/actions/transforms/erase_note_action.h>

#include <fullscore/transforms/erase_note.h>
#include <fullscore/models/note.h>




Action::EraseNote::EraseNote(std::vector<Note> *notes, int index)
   : Base("erase_note")
   , notes(notes)
   , index(index)
{}




Action::EraseNote::~EraseNote()
{}




bool Action::EraseNote::execute()
{
   if (!notes || notes->empty() || index < 0 || index >= notes->size()) return false;

   Transform::EraseNote erase_note_transform(index);
   *notes = erase_note_transform.transform(*notes);
   return true;
}




