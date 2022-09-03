



#include <fullscore/transforms/InsertNoteTransform.h>

#include <fullscore/Transform.h>
#include <AllegroFlare/Useful.hpp>




Transform::InsertNote::InsertNote(int position, Note note)
   : Base(Transform::INSERT_NOTE_TRANSFORM_IDENTIFIER)
   , position(position)
   , note(note)
{
}




Transform::InsertNote::~InsertNote()
{
}




std::vector<Note> Transform::InsertNote::transform(std::vector<Note> notes)
{
   // TODO: vet this
   if (position < 0) position = 0;
   if (position >= notes.size()) position = notes.size()-1;
   //position = limit<int>(0, notes.size(), position);

	notes.insert(notes.begin() + position, note);
   return notes;
}




