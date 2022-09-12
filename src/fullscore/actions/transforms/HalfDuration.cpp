



#include <fullscore/actions/transforms/HalfDuration.hpp>

#include <fullscore/models/Note.hpp>
#include <fullscore/transforms/HalfDurationTransform.hpp>




Action::Transform::HalfDuration::HalfDuration(Note *note)
   : Base("half_duration")
   , note(note)
{}




Action::Transform::HalfDuration::~HalfDuration()
{}




bool Action::Transform::HalfDuration::execute()
{
   if (!note) throw std::runtime_error("Cannot HalfDuration on a nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::HalfDuration half_duration_transform;
   single_note_as_array = half_duration_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




