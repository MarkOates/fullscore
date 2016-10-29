



#include <fullscore/actions/transforms/transpose_transform_action.h>

#include <fullscore/transforms/transpose_transform.h>
#include <fullscore/models/note.h>




Action::TransposeTransform::TransposeTransform(std::vector<Note> *notes, int transposition)
   : Base("transpose")
   , notes(notes)
   , transposition(transposition)
{}




Action::TransposeTransform::~TransposeTransform()
{}




bool Action::TransposeTransform::execute()
{
   if (!notes) return false;

   Transform::Transpose transpose_transform(transposition);
   *notes = transpose_transform.transform(*notes);

   return true;
}




