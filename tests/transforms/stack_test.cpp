


#include <gtest/gtest.h>

#include <fullscore/transforms/stack.h>

#include <fullscore/transforms/insert_note.h>



TEST(TransformStackTest, can_be_created)
{
   Transform::Stack transform_stack;
}



TEST(TransformStackTest, has_an_identifier_of_stack)
{
   Transform::Stack transform_stack;
   EXPECT_EQ("stack", transform_stack.get_identifier());
}



TEST(TransformStackTest, executes_the_sequence_of_transforms)
{
   std::vector<Note> source_notes = {};
   Transform::Stack transform_stack;

   Transform::InsertNote insert_note_transform(0, Note());

   for (unsigned i=0; i<3; i++)
      transform_stack.add_transform(&insert_note_transform);

   std::vector<Note> expected_notes = { Note(), Note(), Note() };
   std::vector<Note> returned_notes = transform_stack.transform(source_notes);

   EXPECT_EQ(expected_notes, returned_notes);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



