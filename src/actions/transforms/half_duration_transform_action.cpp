



#include <fullscore/actions/transforms/half_duration_transform_action.h>

#include <fullscore/transforms/half_duration_transform.h>
#include <fullscore/models/note.h>




Action::HalfDurationTransform::HalfDurationTransform(std::vector<Note> *notes)
   : Base("half_duration")
   , notes(notes)
{}




Action::HalfDurationTransform::~HalfDurationTransform()
{}




bool Action::HalfDurationTransform::execute()
{
   if (!notes) return false;

   Transform::HalfDuration half_duration_transform;
   *notes = half_duration_transform.transform(*notes);

   return true;
}




