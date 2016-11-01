



#include <fullscore/actions/transforms/remove_dot_transform_action.h>

#include <fullscore/transforms/remove_dot_transform.h>
#include <fullscore/models/note.h>




Action::RemoveDotTransform::RemoveDotTransform(Note *note)
   : Base("remove_dot_transform")
   , note(note)
{}




Action::RemoveDotTransform::~RemoveDotTransform()
{}




bool Action::RemoveDotTransform::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::RemoveDot remove_dot_transform;
   single_note_as_array = remove_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




