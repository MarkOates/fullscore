



#include <fullscore/actions/transforms/remove_dot_transform_action.h>

#include <fullscore/transforms/remove_dot_transform.h>
#include <fullscore/models/note.h>




Action::RemoveDotTransform::RemoveDotTransform(std::vector<Note> *notes)
   : Base("remove_dot_transform")
   , notes(notes)
{}




Action::RemoveDotTransform::~RemoveDotTransform()
{}




bool Action::RemoveDotTransform::execute()
{
   if (!notes) return false;

   Transform::RemoveDot remove_dot_transform;
   *notes = remove_dot_transform.transform(*notes);

   return true;
}




