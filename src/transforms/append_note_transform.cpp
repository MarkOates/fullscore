



#include <fullscore/transforms/append_note_transform.h>

#include <allegro_flare/useful.h>




Transform::AppendNote::AppendNote(Note note)
   : Base("append_note")
   , note(note)
{
}




Transform::AppendNote::~AppendNote()
{
}




std::vector<Note> Transform::AppendNote::transform(std::vector<Note> notes)
{
	notes.push_back(note);
   return notes;
}




