


#include <gtest/gtest.h>

#include <fullscore/Transforms/SplitNoteTransform.hpp>



TEST(SplitNoteTest, splits_notes_into_half)
{
   std::vector<Note> returned_notes = ::Transforms::SplitNote().transform({
         Note(3, Duration::HALF),
         Note(5, Duration::WHOLE),
         Note(7, Duration::QUARTER),
      });

   std::vector<Note> expected_notes = {
      Note(3, Duration::QUARTER),
      Note(3, Duration::QUARTER),
      Note(5, Duration::HALF),
      Note(5, Duration::HALF),
      Note(7, Duration::EIGHTH),
      Note(7, Duration::EIGHTH),
   };

   ASSERT_EQ(expected_notes, returned_notes);
}



