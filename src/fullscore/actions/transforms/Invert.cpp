



#include <fullscore/actions/Transforms/Invert.hpp>

#include <fullscore/models/Note.hpp>
#include <fullscore/Transforms/InvertTransform.hpp>




Action::Transforms::Invert::Invert(Note *note, int axis)
   : Base("invert")
   , note(note)
   , axis(axis)
{}




Action::Transforms::Invert::~Invert()
{}




bool Action::Transforms::Invert::execute()
{
   if (!note) throw std::runtime_error("Cannot Invert nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transforms::Invert invert_transform(axis);
   single_note_as_array = invert_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




