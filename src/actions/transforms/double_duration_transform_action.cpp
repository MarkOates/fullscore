



#include <fullscore/actions/transforms/double_duration_transform_action.h>

#include <fullscore/transforms/double_duration.h>
#include <fullscore/models/note.h>




Action::DoubleDurationTransform::DoubleDurationTransform(Note *note)
   : Base("double_duration")
   , note(note)
{}




Action::DoubleDurationTransform::~DoubleDurationTransform()
{}




bool Action::DoubleDurationTransform::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::DoubleDuration double_duration_transform;
   single_note_as_array = double_duration_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}



