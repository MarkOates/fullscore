


#include <fullscore/actions/transforms/AddDotToNote.h>

#include <fullscore/transforms/add_dot_transform.h>
#include <fullscore/models/Note.h>



Action::Transform::AddDotToNote::AddDotToNote(Note *note)
   : Base("add_dot_to_note")
   , note(note)
{}



Action::Transform::AddDotToNote::~AddDotToNote()
{}



bool Action::Transform::AddDotToNote::execute()
{
   if (!note) throw std::runtime_error("Cannot add_dot_to_note to nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::AddDot add_dot_transform;
   single_note_as_array = add_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}



