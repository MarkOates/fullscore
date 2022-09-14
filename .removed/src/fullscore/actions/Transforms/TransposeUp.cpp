



#include <fullscore/actions/Transforms/TransposeUp.hpp>

#include <fullscore/models/Note.hpp>
#include <fullscore/Transforms/TransposeTransform.hpp>




Action::Transforms::TransposeUp::TransposeUp(Note *note)
   : Base("transpose_up")
   , note(note)
{}




Action::Transforms::TransposeUp::~TransposeUp()
{}




bool Action::Transforms::TransposeUp::execute()
{
   if (!note) throw std::runtime_error("Cannot TransposeUp on a nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transforms::Transpose transpose_transform(1);
   single_note_as_array = transpose_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




