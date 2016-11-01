



#include <fullscore/actions/transforms/transpose_transform_action.h>

#include <fullscore/transforms/transpose_transform.h>
#include <fullscore/models/note.h>




Action::TransposeTransform::TransposeTransform(Note *note, int transposition)
   : Base("transpose")
   , note(note)
   , transposition(transposition)
{}




Action::TransposeTransform::~TransposeTransform()
{}




bool Action::TransposeTransform::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::Transpose transpose_transform(transposition);
   single_note_as_array = transpose_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




