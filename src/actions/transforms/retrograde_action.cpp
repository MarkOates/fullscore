



#include <fullscore/actions/transforms/retrograde_action.h>

#include <fullscore/transforms/retrograde_transform.h>
#include <fullscore/models/note.h>




Action::Transform::Retrograde::Retrograde(std::vector<Note> *notes)
   : Base("retrograde")
   , notes(notes)
{}




Action::Transform::Retrograde::~Retrograde()
{}




bool Action::Transform::Retrograde::execute()
{
   if (!notes) return false;

   ::Transform::Retrograde retrograde_transform;
   *notes = retrograde_transform.transform(*notes);

   return true;
}




