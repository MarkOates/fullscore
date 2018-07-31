



#include <fullscore/actions/transforms/Retrograde.h>

#include <fullscore/transforms/RetrogradeTransform.h>
#include <fullscore/models/Note.h>




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




