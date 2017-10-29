



#include <fullscore/actions/transforms/RemoveDot.h>

#include <fullscore/transforms/remove_dot_transform.h>
#include <fullscore/models/Note.h>




Action::Transform::RemoveDot::RemoveDot(Note *note)
   : Base("remove_dot_transform")
   , note(note)
{}




Action::Transform::RemoveDot::~RemoveDot()
{}




bool Action::Transform::RemoveDot::execute()
{
   if (!note) throw std::runtime_error("Cannot RemoveDot nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::RemoveDot remove_dot_transform;
   single_note_as_array = remove_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




