


#include <gtest/gtest.h>

#include <fullscore/transforms/insert_note_transform.h>



TEST(InsertNoteTransformTest, can_insert_notes_at_the_end)
{
   std::vector<Note> notes = {
      Note(2),
      Note(3),
   };

   Transform::InsertNote insert_note_transform(notes.size(), Note(4));

   std::vector<Note> expected_notes = {
      Note(2),
      Note(3),
      Note(4),
   };

   std::vector<Note> returned_notes = insert_note_transform.transform(notes);

   ASSERT_EQ(expected_notes, returned_notes);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



