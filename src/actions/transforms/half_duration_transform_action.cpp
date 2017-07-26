



#include <fullscore/actions/transforms/half_duration_transform_action.h>

#include <fullscore/models/note.h>
#include <fullscore/transforms/half_duration_transform.h>




Action::HalfDurationTransform::HalfDurationTransform(Note *note)
   : Base("half_duration")
   , note(note)
{}




Action::HalfDurationTransform::~HalfDurationTransform()
{}




bool Action::HalfDurationTransform::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::HalfDuration half_duration_transform;
   single_note_as_array = half_duration_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




