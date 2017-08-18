



#include <fullscore/actions/transforms/InsertNoteAfter.h>

#include <fullscore/actions/transforms/InsertNote.h>
#include <fullscore/actions/move_cursor_right_action.h>
#include <fullscore/action.h>



Action::Transform::InsertNoteAfter::InsertNoteAfter(UIGridEditor *grid_editor, std::vector<Note> *notes, int at_index, Note note)
   : Base(INSERT_NOTE_AFTER_TRANSFORM_IDENTIFIER)
   , grid_editor(grid_editor)
   , notes(notes)
   , at_index(at_index)
   , note(note)
{}




Action::Transform::InsertNoteAfter::~InsertNoteAfter()
{}




bool Action::Transform::InsertNoteAfter::execute()
{
   if (!notes) throw std::runtime_error("Cannot transform nullptr notes");

   try
   {
      Action::Transform::InsertNote(notes, at_index+1, note).execute();
      Action::MoveCursorRight(grid_editor).execute();
   }
   catch (std::runtime_error const &e)
   {
      throw std::runtime_error("Cannot InsertNoteAfter; Sub actions threw an exception");
   }

   return true;
}




