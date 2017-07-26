


#include <fullscore/actions/transforms/octatonic_1_transform_action.h>

#include <fullscore/transforms/octatonic_1_transform.h>
#include <fullscore/models/note.h>



Action::Octatonic1Transform::Octatonic1Transform(std::vector<Note> *notes)
   : Base("octatonic_1_transform")
   , notes(notes)
{}



Action::Octatonic1Transform::~Octatonic1Transform()
{}



bool Action::Octatonic1Transform::execute()
{
   if (!notes) return false;

   ::Transform::Octatonic1 octatonic_1_transform;
   *notes = octatonic_1_transform.transform(*notes);

   return true;
}



