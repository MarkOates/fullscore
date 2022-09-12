



#include <fullscore/actions/transforms/Retrograde.hpp>

#include <fullscore/transforms/RetrogradeTransform.hpp>
#include <fullscore/models/Note.hpp>




Action::Transform::Retrograde::Retrograde(std::vector<Note> *notes)
   : Base("retrograde")
   , notes(notes)
{}




Action::Transform::Retrograde::~Retrograde()
{}




bool Action::Transform::Retrograde::execute()
{
   if (!notes) throw std::runtime_error("Cannot Retrograde on nullptr notes");

   ::Transform::Retrograde retrograde_transform;
   *notes = retrograde_transform.transform(*notes);

   return true;
}




