



#include <fullscore/actions/transforms/RemoveDot.hpp>

#include <fullscore/transforms/RemoveDotTransform.hpp>
#include <fullscore/models/Note.hpp>
#include <fullscore/ActionNames.hpp>




Action::Transform::RemoveDot::RemoveDot(Note *note)
   : Base(ActionNames::REMOVE_DOT_ACTION_IDENTIFIER)
   , note(note)
{}




Action::Transform::RemoveDot::~RemoveDot()
{}




bool Action::Transform::RemoveDot::execute()
{
   if (!note) throw std::runtime_error("Cannot RemoveDot nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::RemoveDot remove_dot_transform;
   single_note_as_array = remove_dot_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




