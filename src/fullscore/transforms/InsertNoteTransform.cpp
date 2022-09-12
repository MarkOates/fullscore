



#include <fullscore/transforms/InsertNoteTransform.hpp>

#include <fullscore/TransformNames.hpp>
#include <AllegroFlare/Useful.hpp>




Transform::InsertNote::InsertNote(int position, Note note)
   : Base(TransformNames::INSERT_NOTE_TRANSFORM_IDENTIFIER)
   , position(position)
   , note(note)
{
}




Transform::InsertNote::~InsertNote()
{
}




std::vector<Note> Transform::InsertNote::transform(std::vector<Note> notes)
{
   if (position < 0) position = 0;
   if (position > notes.size()) position = notes.size();

   notes.insert(notes.begin() + position, note);
   return notes;
}




