


#include <fullscore/actions/transforms/Descend.hpp>

#include <fullscore/transforms/DescendTransform.hpp>
#include <fullscore/models/Note.hpp>



Action::Transform::Descend::Descend(std::vector<Note> *notes)
   : Base("descend")
   , notes(notes)
{}



Action::Transform::Descend::~Descend()
{}



bool Action::Transform::Descend::execute()
{
   if (!notes) throw std::runtime_error("Cannot perform Descend action on nullptr notes");

   *notes = ::Transform::Descend().transform(*notes);

   return true;
}



