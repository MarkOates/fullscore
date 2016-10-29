



#include <fullscore/actions/transforms/double_duration_transform_action.h>

#include <fullscore/transforms/double_duration_transform.h>
#include <fullscore/models/note.h>




Action::DoubleDurationTransform::DoubleDurationTransform(std::vector<Note> *notes)
   : Base("double_duration")
   , notes(notes)
{}




Action::DoubleDurationTransform::~DoubleDurationTransform()
{}




bool Action::DoubleDurationTransform::execute()
{
   if (!notes) return false;

   Transform::DoubleDuration double_duration_transform;
   *notes = double_duration_transform.transform(*notes);

   return true;
}




