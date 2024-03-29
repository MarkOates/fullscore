


#include <gtest/gtest.h>

#include <fullscore/Transforms/DescendTransform.hpp>



TEST(DescendTransformTest, causes_subsequent_pitches_to_descend_from_the_initial_scale_degree)
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
      Note(1, Duration::QUARTER),
      Note(0, Duration::HALF),
      Note(-1, Duration::WHOLE),
      Note(-2, Duration::SIXTEENTH),
   };

   std::vector<Note> returned_notes = Transforms::Descend().transform(notes);

   ASSERT_EQ(expected_notes, returned_notes);
}



