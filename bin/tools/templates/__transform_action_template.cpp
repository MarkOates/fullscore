


#include <fullscore/actions/transforms/SNAKECASE_ACTION_NAME_action.h>

#include <fullscore/transforms/SNAKECASE_ACTION_NAME_transform.h>
#include <fullscore/models/Note.h>



Action::CLASS_NAME::CLASS_NAME(std::vector<Note> *notes)
   : Base("SNAKECASE_ACTION_NAME")
   , notes(notes)
{}



Action::CLASS_NAME::~CLASS_NAME()
{}



bool Action::CLASS_NAME::execute()
{
   if (!notes) return false;

   // unimplemented
   return false;
}



