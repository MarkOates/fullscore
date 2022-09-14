



#include <fullscore/actions/Transforms/EraseNote.hpp>

#include <fullscore/models/Note.hpp>
#include <fullscore/Transforms/EraseNoteTransform.hpp>




Action::Transforms::EraseNote::EraseNote(std::vector<Note> *notes, int index)
   : Base("erase_note")
   , notes(notes)
   , index(index)
{}




Action::Transforms::EraseNote::~EraseNote()
{}




bool Action::Transforms::EraseNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot EraseNote on a nullptr note");
   if (notes->empty() || index < 0 || index >= notes->size()) throw std::runtime_error("Cannot EraseNote at out of bounds index");

   ::Transforms::EraseNote erase_note_transform(index);
   *notes = erase_note_transform.transform(*notes);

   return true;
}




