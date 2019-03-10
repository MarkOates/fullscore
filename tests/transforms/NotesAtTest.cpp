


#include <gtest/gtest.h>

#include <fullscore/transforms/NoteSet.h>
#include <fullscore/transforms/NotesAt.h>



TEST(NotesAtTest, with_negative_values_for_indexes_raises_an_error)
{
   NoteSet note_set(
      { 0, Duration::DURATION_QUARTER },
      { 1, Duration::DURATION_QUARTER },
   );

   throw std::runtime_error("Unfinished test");

   // expect this to raise an exception
   Transform::NotesAt({ -1 }).transform(note_set);
}


TEST(NotesAtTest, with_index_values_that_are_beyond_the_range_of_the_notes_ignores_them)
{
   NoteSet note_set(
      { 0, Duration::DURATION_QUARTER },
      { 1, Duration::DURATION_QUARTER },
   );

   throw std::runtime_error("Unfinished test");

   // expect this to raise an exception
   returned_notes = Transform::NotesAt({ 1, 2 }).transform(note_set);

   ASSERT_EQ(1, returned_notes.size());
}




