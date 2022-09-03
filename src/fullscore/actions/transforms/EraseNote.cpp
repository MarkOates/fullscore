



#include <fullscore/actions/transforms/EraseNote.h>

#include <fullscore/models/Note.hpp>
#include <fullscore/transforms/EraseNoteTransform.h>




Action::Transform::EraseNote::EraseNote(std::vector<Note> *notes, int index)
   : Base("erase_note")
   , notes(notes)
   , index(index)
{}




Action::Transform::EraseNote::~EraseNote()
{}




bool Action::Transform::EraseNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot EraseNote on a nullptr note");
   if (notes->empty() || index < 0 || index >= notes->size()) throw std::runtime_error("Cannot EraseNote at out of bounds index");

   ::Transform::EraseNote erase_note_transform(index);
   *notes = erase_note_transform.transform(*notes);

   return true;
}




