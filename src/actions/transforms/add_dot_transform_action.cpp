



#include <fullscore/actions/transforms/add_dot_transform_action.h>

#include <fullscore/transforms/add_dot_transform.h>
#include <fullscore/models/note.h>




Action::AddDotTransform::AddDotTransform(std::vector<Note> *notes)
   : Base("add_dot_transform")
   , notes(notes)
{}




Action::AddDotTransform::~AddDotTransform()
{}




bool Action::AddDotTransform::execute()
{
   if (!notes) return false;

   Transform::AddDot add_dot_transform;
   *notes = add_dot_transform.transform(*notes);

   return true;
}




