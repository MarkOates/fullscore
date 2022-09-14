



#include <fullscore/actions/Transforms/Retrograde.hpp>

#include <fullscore/Transforms/RetrogradeTransform.hpp>
#include <fullscore/models/Note.hpp>




Action::Transforms::Retrograde::Retrograde(std::vector<Note> *notes)
   : Base("retrograde")
   , notes(notes)
{}




Action::Transforms::Retrograde::~Retrograde()
{}




bool Action::Transforms::Retrograde::execute()
{
   if (!notes) throw std::runtime_error("Cannot Retrograde on nullptr notes");

   ::Transforms::Retrograde retrograde_transform;
   *notes = retrograde_transform.transform(*notes);

   return true;
}




