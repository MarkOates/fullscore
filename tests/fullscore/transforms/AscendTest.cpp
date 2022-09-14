


#include <gtest/gtest.h>

#include <fullscore/Transforms/Ascend.hpp>



TEST(AscendTest, causes_subsequent_pitches_to_ascend_from_the_initial_scale_degree)
{
   std::vector<Note> notes = {
      Note(2, Duration::HALF),
      Note(-6, Duration::QUARTER),
      Note(8, Duration::HALF),
      Note(4, Duration::WHOLE),
      Note(5, Duration::SIXTEENTH),
   };

   std::vector<Note> expected_notes = {
      Note(2, Duration::HALF),
      Note(3, Duration::QUARTER),
      Note(4, Duration::HALF),
      Note(5, Duration::WHOLE),
      Note(6, Duration::SIXTEENTH),
   };

   std::vector<Note> returned_notes = Transforms::Ascend().transform(notes);

   ASSERT_EQ(expected_notes, returned_notes);
}



