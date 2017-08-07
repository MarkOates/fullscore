



#include <fullscore/actions/transforms/Invert.h>

#include <fullscore/models/note.h>
#include <fullscore/transforms/invert_transform.h>




Action::Transform::Invert::Invert(Note *note, int axis)
   : Base("invert")
   , note(note)
   , axis(axis)
{}




Action::Transform::Invert::~Invert()
{}




bool Action::Transform::Invert::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   ::Transform::Invert invert_transform(axis);
   single_note_as_array = invert_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




