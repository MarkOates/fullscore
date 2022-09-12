


#include <gtest/gtest.h>

#ifndef ASSERT_THROW_WITH_MESSAGE
#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }
#endif


#include <fullscore/models/NoteSet.hpp>
#include <fullscore/Transforms/NotesAtTransform.hpp>



TEST(NotesAtTransformTest, with_negative_values_for_indexes_raises_an_error)
{
   NoteSet note_set({
      { 0, Duration::QUARTER },
      { 1, Duration::QUARTER }
   });

   std::string expected_error_message = "Transforms::NotesAt::transform() error: cannot have index greater than the number of elements in the set (index: -1, set_size: 2).";

   Transforms::NotesAt transform({ -1 });

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

   //std::string expected_error_message = "Transforms::NotesAt::transform() error: cannot have index greater than the number of elements in the set (index: -1, set_size: 2).";

   //std::vector<Note> returned_notes = Transforms::NotesAt({ 1, 2 }).transform(note_set.get_notes());

   //ASSERT_EQ(1, returned_notes.size());
}




