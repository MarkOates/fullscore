


#include <fullscore/actions/Transforms/Octatonic1.hpp>

#include <fullscore/Transforms/Octatonic1Transform.hpp>
#include <fullscore/models/Note.hpp>



Action::Transforms::Octatonic1::Octatonic1(std::vector<Note> *notes)
   : Base("octatonic_1")
   , notes(notes)
{}



::Action::Transforms::Octatonic1::~Octatonic1()
{}



bool Action::Transforms::Octatonic1::execute()
{
   if (!notes) throw std::runtime_error("Cannot Octatonic1 nullptr notes");

   ::Transforms::Octatonic1 octatonic_1_transform;
   *notes = octatonic_1_transform.transform(*notes);

   return true;
}



