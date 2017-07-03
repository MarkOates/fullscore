



#include <fullscore/actions/transforms/toggle_rest_action.h>

#include <fullscore/transforms/toggle_rest.h>
#include <fullscore/models/note.h>




Action::ToggleRest::ToggleRest(Note *note)
   : Base("toggle_rest")
   , note(note)
{}




Action::ToggleRest::~ToggleRest()
{}




bool Action::ToggleRest::execute()
{
   if (!note) return false;

   std::vector<Note> single_note_as_array;
   single_note_as_array.push_back(*note);

   Transform::ToggleRest toggle_rest_transform;
   single_note_as_array = toggle_rest_transform.transform(single_note_as_array);

   *note = single_note_as_array.at(0);

   return true;
}




