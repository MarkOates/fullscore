



#include <fullscore/actions/transforms/DoubleDuration.hpp>

#include <fullscore/transforms/DoubleDurationTransform.hpp>
#include <fullscore/models/Note.hpp>




Action::Transform::DoubleDuration::DoubleDuration(Note *note)
   : Base("double_duration")
   , note(note)
{}




Action::Transform::DoubleDuration::~DoubleDuration()
{}




bool Action::Transform::DoubleDuration::execute()
{
   if (!note) throw std::runtime_error("Cannot double_duration on a nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::DoubleDuration double_duration_transform;
   single_note_as_array = double_duration_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




