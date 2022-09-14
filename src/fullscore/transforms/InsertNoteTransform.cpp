



#include <fullscore/Transforms/InsertNoteTransform.hpp>

#include <fullscore/TransformNames.hpp>
#include <AllegroFlare/Useful.hpp>




Transforms::InsertNote::InsertNote(int position, Note note)
   : Base(TransformNames::INSERT_NOTE_TRANSFORM_IDENTIFIER)
   , position(position)
   , note(note)
{
}




Transforms::InsertNote::~InsertNote()
{
}




std::vector<Note> Transforms::InsertNote::transform(std::vector<Note> notes)
{
   if (position < 0) position = 0;
   if (position > notes.size()) position = notes.size();

   notes.insert(notes.begin() + position, note);
   return notes;
}




