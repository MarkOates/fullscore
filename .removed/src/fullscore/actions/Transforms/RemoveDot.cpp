



#include <fullscore/actions/Transforms/RemoveDot.hpp>

#include <fullscore/Transforms/RemoveDotTransform.hpp>
#include <fullscore/models/Note.hpp>
#include <fullscore/ActionNames.hpp>




Action::Transforms::RemoveDot::RemoveDot(Note *note)
   : Base(ActionNames::REMOVE_DOT_ACTION_IDENTIFIER)
   , note(note)
{}




Action::Transforms::RemoveDot::~RemoveDot()
{}




bool Action::Transforms::RemoveDot::execute()
{
   if (!note) throw std::runtime_error("Cannot RemoveDot nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transforms::RemoveDot remove_dot_transform;
   single_note_as_array = remove_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




