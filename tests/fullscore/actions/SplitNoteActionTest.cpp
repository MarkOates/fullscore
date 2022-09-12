


#include <gtest/gtest.h>

#include <fullscore/actions/Transforms/SplitNote.hpp>

#include <fullscore/models/Duration.hpp>
#include <fullscore/models/Note.hpp>



TEST(SplitNoteActionTest, splits_the_source_notes_into_half)
{
   std::vector<Note> source_notes = {
         Note(3, Duration::HALF),
         Note(5, Duration::WHOLE),
         Note(7, Duration::QUARTER),
      };

   ::Action::Transforms::SplitNote split_note_action(&source_notes);

   std::vector<Note> expected_notes = {
      Note(3, Duration::QUARTER),
      Note(3, Duration::QUARTER),
      Note(5, Duration::HALF),
      Note(5, Duration::HALF),
      Note(7, Duration::EIGHTH),
      Note(7, Duration::EIGHTH),
   };

   ASSERT_EQ(true, split_note_action.execute());

   ASSERT_EQ(expected_notes, source_notes);
}



