


#include <fullscore/actions/transforms/InsertNoteAfter.h>

#include <fullscore/actions/transforms/InsertNote.h>
#include <fullscore/Action.h>



Action::Transform::InsertNoteAfter::InsertNoteAfter(std::vector<Note> *notes, int at_index, Note note)
   : Base(INSERT_NOTE_AFTER_TRANSFORM_IDENTIFIER)
   , notes(notes)
   , at_index(at_index)
   , note(note)
{
}



Action::Transform::InsertNoteAfter::~InsertNoteAfter()
{}



bool Action::Transform::InsertNoteAfter::execute()
{
   if (!notes) throw std::runtime_error("Cannot InsertNoteAfter nullptr notes");

   try
   {
      Action::Transform::InsertNote(notes, at_index+1, note).execute();
   }
   catch (std::runtime_error const &e)
   {
      throw std::runtime_error("Cannot InsertNoteAfter; Sub actions threw an exception");
   }

   return true;
}



