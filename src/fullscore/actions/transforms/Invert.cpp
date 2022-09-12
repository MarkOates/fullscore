



#include <fullscore/actions/transforms/Invert.hpp>

#include <fullscore/models/Note.hpp>
#include <fullscore/transforms/InvertTransform.hpp>




Action::Transform::Invert::Invert(Note *note, int axis)
   : Base("invert")
   , note(note)
   , axis(axis)
{}




Action::Transform::Invert::~Invert()
{}




bool Action::Transform::Invert::execute()
{
   if (!note) throw std::runtime_error("Cannot Invert nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::Invert invert_transform(axis);
   single_note_as_array = invert_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




