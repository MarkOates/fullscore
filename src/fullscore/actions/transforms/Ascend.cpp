


#include <fullscore/actions/transforms/Ascend.h>

#include <fullscore/transforms/AscendTransform.h>
#include <fullscore/models/Note.h>



Action::Transform::Ascend::Ascend(std::vector<Note> *notes)
   : Base("ascend")
   , notes(notes)
{}



Action::Transform::Ascend::~Ascend()
{}



bool Action::Transform::Ascend::execute()
{
   if (!notes) throw std::runtime_error("Cannot perform Ascend action on nullptr notes");

   *notes = ::Transform::Ascend().transform(*notes);

   return true;
}



