



#include <fullscore/actions/transforms/invert_action.h>

#include <fullscore/transforms/invert_transform.h>
#include <fullscore/models/note.h>




Action::Transform::Invert::Invert(std::vector<Note> *notes, int axis)
   : Base("invert")
   , notes(notes)
   , axis(axis)
{}




Action::Transform::Invert::~Invert()
{}




bool Action::Transform::Invert::execute()
{
   if (!notes) return false;

   ::Transform::Invert invert_transform(axis);
   *notes = invert_transform.transform(*notes);

   return true;
}




