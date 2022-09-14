


#include <fullscore/actions/Transforms/SplitNote.hpp>

#include <fullscore/Transforms/SplitNoteTransform.hpp>
#include <fullscore/models/Note.hpp>



Action::Transforms::SplitNote::SplitNote(std::vector<Note> *notes)
   : Base("split_note")
   , notes(notes)
{}



Action::Transforms::SplitNote::~SplitNote()
{}



bool Action::Transforms::SplitNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot SplitNote on nullptr notes");

   ::Transforms::SplitNote split_note_transform;
   *notes = split_note_transform.transform(*notes);

   return true;
}



