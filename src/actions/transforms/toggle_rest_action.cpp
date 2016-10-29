



#include <fullscore/actions/transforms/toggle_rest_action.h>

#include <fullscore/transforms/toggle_rest_transform.h>
#include <fullscore/models/note.h>




Action::ToggleRest::ToggleRest(std::vector<Note> *notes)
   : Base("toggle_rest")
   , notes(notes)
{}




Action::ToggleRest::~ToggleRest()
{}




bool Action::ToggleRest::execute()
{
   if (!notes) return false;

   Transform::ToggleRest toggle_rest_transform;
   *notes = toggle_rest_transform.transform(*notes);
   return true;
}




