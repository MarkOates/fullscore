


#include <gtest/gtest.h>

#include "../TestHelper.hpp"

#include <fullscore/models/NoteSet.hpp>
#include <fullscore/transforms/NotesAtTransform.h>



TEST(NotesAtTransformTest, with_negative_values_for_indexes_raises_an_error)
{
   NoteSet note_set({
      { 0, Duration::QUARTER },
      { 1, Duration::QUARTER }
   });

   std::string expected_error_message = "Transform::NotesAt::transform() error: cannot have index greater than the number of elements in the set (index: -1, set_size: 2).";

   Transform::NotesAt transform({ -1 });

   ASSERT_THROW_WITH_MESSAGE(
      transform.transform(note_set.get_notes()),
      std::runtime_error,
      expected_error_message
   )
}


TEST(NotesAtTransformTest, with_index_values_that_are_beyond_the_range_of_the_notes_ignores_them)
{
   NoteSet note_set({
      { 0, Duration::QUARTER },
      { 1, Duration::QUARTER }
   });

   //std::string expected_error_message = "Transform::NotesAt::transform() error: cannot have index greater than the number of elements in the set (index: -1, set_size: 2).";

   //std::vector<Note> returned_notes = Transform::NotesAt({ 1, 2 }).transform(note_set.get_notes());

   //ASSERT_EQ(1, returned_notes.size());
}




