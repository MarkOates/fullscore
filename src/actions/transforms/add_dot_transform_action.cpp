



#include <fullscore/actions/transforms/add_dot_transform_action.h>

#include <fullscore/transforms/add_dot_transform.h>
#include <fullscore/models/note.h>




Action::AddDotTransform::AddDotTransform(Note *note)
   : Base("add_dot_transform")
   , note(note)
{}




Action::AddDotTransform::~AddDotTransform()
{}




bool Action::AddDotTransform::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::AddDot add_dot_transform;
   single_note_as_array = add_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




