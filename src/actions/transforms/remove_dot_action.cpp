



#include <fullscore/actions/transforms/remove_dot_action.h>

#include <fullscore/transforms/remove_dot_transform.h>
#include <fullscore/models/note.h>




Action::Transform::RemoveDot::RemoveDot(Note *note)
   : Base("remove_dot_transform")
   , note(note)
{}




Action::Transform::RemoveDot::~RemoveDot()
{}




bool Action::Transform::RemoveDot::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::RemoveDot remove_dot_transform;
   single_note_as_array = remove_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




