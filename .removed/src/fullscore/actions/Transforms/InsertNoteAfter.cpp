


#include <fullscore/actions/Transforms/InsertNoteAfter.hpp>

#include <fullscore/actions/Transforms/InsertNote.hpp>
#include <fullscore/ActionNames.hpp>



Action::Transforms::InsertNoteAfter::InsertNoteAfter(std::vector<Note> *notes, int at_index, Note note)
   : Base(ActionNames::INSERT_NOTE_AFTER_TRANSFORM_IDENTIFIER)
   , notes(notes)
   , at_index(at_index)
   , note(note)
{
}



Action::Transforms::InsertNoteAfter::~InsertNoteAfter()
{}



bool Action::Transforms::InsertNoteAfter::execute()
{
   if (!notes) throw std::runtime_error("Cannot InsertNoteAfter nullptr notes");

   try
   {
      Action::Transforms::InsertNote(notes, at_index+1, note).execute();
   }
   catch (std::runtime_error const &e)
   {
      throw std::runtime_error("Cannot InsertNoteAfter; Sub actions threw an exception");
   }

   return true;
}



