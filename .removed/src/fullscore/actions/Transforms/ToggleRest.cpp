



#include <fullscore/actions/Transforms/ToggleRest.hpp>

#include <fullscore/Transforms/ToggleRestTransform.hpp>
#include <fullscore/models/Note.hpp>




Action::Transforms::ToggleRest::ToggleRest(Note *note)
   : Base("toggle_rest")
   , note(note)
{}




Action::Transforms::ToggleRest::~ToggleRest()
{}




bool Action::Transforms::ToggleRest::execute()
{
   if (!note) throw std::runtime_error("Cannot ToggleRest on a nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transforms::ToggleRest toggle_rest_transform;
   single_note_as_array = toggle_rest_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




