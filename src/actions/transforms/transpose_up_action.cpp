



#include <fullscore/actions/transforms/transpose_up_action.h>

#include <fullscore/transforms/transpose_transform.h>
#include <fullscore/models/note.h>




Action::TransposeUp::TransposeUp(Note *note)
   : Base("transpose_up")
   , note(note)
{}




Action::TransposeUp::~TransposeUp()
{}




bool Action::TransposeUp::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::Transpose transpose_transform(1);
   single_note_as_array = transpose_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}



