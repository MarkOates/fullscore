



#include <fullscore/actions/transforms/AddDot.h>

#include <fullscore/transforms/add_dot_transform.h>
#include <fullscore/models/Note.h>




Action::Transform::AddDot::AddDot(Note *note)
   : Base("add_dot_transform")
   , note(note)
{}




Action::Transform::AddDot::~AddDot()
{}




bool Action::Transform::AddDot::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::AddDot add_dot_transform;
   single_note_as_array = add_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}



