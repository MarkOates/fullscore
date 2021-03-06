


#include <fullscore/actions/transforms/SplitNote.h>

#include <fullscore/transforms/SplitNoteTransform.h>
#include <fullscore/models/Note.h>



Action::Transform::SplitNote::SplitNote(std::vector<Note> *notes)
   : Base("split_note")
   , notes(notes)
{}



Action::Transform::SplitNote::~SplitNote()
{}



bool Action::Transform::SplitNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot SplitNote on nullptr notes");

   ::Transform::SplitNote split_note_transform;
   *notes = split_note_transform.transform(*notes);

   return true;
}



