


#include <fullscore/actions/transforms/Ascend.hpp>

#include <fullscore/transforms/AscendTransform.hpp>
#include <fullscore/models/Note.hpp>



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



