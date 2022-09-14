


#include <fullscore/actions/Transforms/AppendNote.hpp>

#include <fullscore/Transforms/AppendNoteTransform.hpp>



Action::Transforms::AppendNote::AppendNote(std::vector<Note> *notes, Note note)
   : Base("append_note")
   , notes(notes)
   , note(note)
{}



Action::Transforms::AppendNote::~AppendNote()
{}



bool Action::Transforms::AppendNote::execute()
{
   if (!notes) throw std::runtime_error("Cannot append_note to nullptr notes");

   ::Transforms::AppendNote append_note_transform(note);
   *notes = append_note_transform.transform(*notes);

   return true;
}



