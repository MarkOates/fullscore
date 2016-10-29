



#include <fullscore/actions/transforms/ACTION_NAME.h>

#include <fullscore/transforms/TRANSFORM_NAME.h>
#include <fullscore/models/note.h>




Action::TEMPLATE::TEMPLATE(std::vector<Note> *notes)
   : Base("TEMPLATE")
   , notes(notes)
{}




Action::TEMPLATE::~TEMPLATE()
{}




bool Action::TEMPLATE::execute()
{
   if (!notes) return false;

   // unimplemented
   return false;
}




