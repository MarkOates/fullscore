


#include <fullscore/actions/transforms/Octatonic1.h>

#include <fullscore/transforms/octatonic_1_transform.h>
#include <fullscore/models/Note.h>



Action::Transform::Octatonic1::Octatonic1(std::vector<Note> *notes)
   : Base("octatonic_1_transform")
   , notes(notes)
{}



::Action::Transform::Octatonic1::~Octatonic1()
{}



bool Action::Transform::Octatonic1::execute()
{
   if (!notes) return false;

   ::Transform::Octatonic1 octatonic_1_transform;
   *notes = octatonic_1_transform.transform(*notes);

   return true;
}



