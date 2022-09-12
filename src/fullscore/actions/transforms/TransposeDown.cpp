



#include <fullscore/actions/transforms/TransposeDown.hpp>

#include <fullscore/models/Note.hpp>
#include <fullscore/transforms/TransposeTransform.hpp>




Action::Transform::TransposeDown::TransposeDown(Note *note)
   : Base("transpose_down")
   , note(note)
{}




Action::Transform::TransposeDown::~TransposeDown()
{}




bool Action::Transform::TransposeDown::execute()
{
   if (!note) throw std::runtime_error("Cannot TransposeDown on a nullptr note");

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::Transpose transpose_transform(-1);
   single_note_as_array = transpose_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




