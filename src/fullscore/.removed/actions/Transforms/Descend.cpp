


#include <fullscore/actions/Transforms/Descend.hpp>

#include <fullscore/Transforms/DescendTransform.hpp>
#include <fullscore/models/Note.hpp>



Action::Transforms::Descend::Descend(std::vector<Note> *notes)
   : Base("descend")
   , notes(notes)
{}



Action::Transforms::Descend::~Descend()
{}



bool Action::Transforms::Descend::execute()
{
   if (!notes) throw std::runtime_error("Cannot perform Descend action on nullptr notes");

   *notes = ::Transforms::Descend().transform(*notes);

   return true;
}



