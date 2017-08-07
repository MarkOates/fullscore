



#include <fullscore/actions/transforms/HalfDuration.h>

#include <fullscore/models/Note.h>
#include <fullscore/transforms/half_duration_transform.h>




Action::Transform::HalfDuration::HalfDuration(Note *note)
   : Base("half_duration")
   , note(note)
{}




Action::Transform::HalfDuration::~HalfDuration()
{}




bool Action::Transform::HalfDuration::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::HalfDuration half_duration_transform;
   single_note_as_array = half_duration_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




