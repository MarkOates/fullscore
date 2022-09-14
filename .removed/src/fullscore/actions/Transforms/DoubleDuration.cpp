



#include <fullscore/actions/Transforms/DoubleDuration.hpp>

#include <fullscore/Transforms/DoubleDurationTransform.hpp>
#include <fullscore/models/Note.hpp>




Action::Transforms::DoubleDuration::DoubleDuration(Note *note)
   : Base("double_duration")
   , note(note)
{}




Action::Transforms::DoubleDuration::~DoubleDuration()
{}




bool Action::Transforms::DoubleDuration::execute()
{
   if (!note) throw std::runtime_error("Cannot double_duration on a nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transforms::DoubleDuration double_duration_transform;
   single_note_as_array = double_duration_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




