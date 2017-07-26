



#include <fullscore/actions/transforms/transpose_down_action.h>

#include <fullscore/models/note.h>
#include <fullscore/transforms/transpose_transform.h>




Action::TransposeDown::TransposeDown(Note *note)
   : Base("transpose_down")
   , note(note)
{}




Action::TransposeDown::~TransposeDown()
{}




bool Action::TransposeDown::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::Transpose transpose_transform(-1);
   single_note_as_array = transpose_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




