



#include <fullscore/actions/transforms/DoubleDuration.h>

#include <fullscore/transforms/double_duration_transform.h>
#include <fullscore/models/Note.h>




Action::Transform::DoubleDuration::DoubleDuration(Note *note)
   : Base("double_duration")
   , note(note)
{}




Action::Transform::DoubleDuration::~DoubleDuration()
{}




bool Action::Transform::DoubleDuration::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::DoubleDuration double_duration_transform;
   single_note_as_array = double_duration_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




