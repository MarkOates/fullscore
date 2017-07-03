



#include <fullscore/transforms/insert_note.h>

#include <allegro_flare/useful.h>




Transform::InsertNote::InsertNote(int position, Note note)
   : position(position)
   , note(note)
{
}




Transform::InsertNote::~InsertNote()
{
}




std::vector<Note> Transform::InsertNote::transform(std::vector<Note> notes)
{
   position = limit<int>(0, notes.size()-1, position);
	notes.insert(notes.begin() + position, note);
   return notes;
}




