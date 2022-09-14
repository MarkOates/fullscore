


#include <fullscore/actions/Transforms/Ascend.hpp>

#include <fullscore/Transforms/AscendTransform.hpp>
#include <fullscore/models/Note.hpp>



Action::Transforms::Ascend::Ascend(std::vector<Note> *notes)
   : Base("ascend")
   , notes(notes)
{}



Action::Transforms::Ascend::~Ascend()
{}



bool Action::Transforms::Ascend::execute()
{
   if (!notes) throw std::runtime_error("Cannot perform Ascend action on nullptr notes");

   *notes = ::Transforms::Ascend().transform(*notes);

   return true;
}



