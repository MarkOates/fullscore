



#include <fullscore/actions/transforms/ToggleRest.h>

#include <fullscore/transforms/ToggleRestTransform.h>
#include <fullscore/models/Note.h>




Action::Transform::ToggleRest::ToggleRest(Note *note)
   : Base("toggle_rest")
   , note(note)
{}




Action::Transform::ToggleRest::~ToggleRest()
{}




bool Action::Transform::ToggleRest::execute()
{
   if (!note) throw std::runtime_error("Cannot ToggleRest on a nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::ToggleRest toggle_rest_transform;
   single_note_as_array = toggle_rest_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




