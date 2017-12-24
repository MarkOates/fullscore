



#include <fullscore/transforms/InsertNoteTransform.h>

#include <allegro_flare/useful.h>




Transform::InsertNote::InsertNote(int position, Note note)
   : Base("insert_note")
   , position(position)
   , note(note)
{
}




Transform::InsertNote::~InsertNote()
{
}




std::vector<Note> Transform::InsertNote::transform(std::vector<Note> notes)
{
   position = limit<int>(0, notes.size(), position);
	notes.insert(notes.begin() + position, note);
   return notes;
}




