


#include <gtest/gtest.h>

#include <fullscore/transforms/stack_transform.h>

#include <fullscore/transforms/insert_note_transform.h>
#include <fullscore/transforms/reference_transform.h>
#include <fullscore/transforms/retrograde_transform.h>
#include <fullscore/transforms/toggle_rest_transform.h>



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



TEST(TransformStackTest, returns_a_list_of_transforms)
{
   Transform::Stack transform_stack;

   Transform::InsertNote insert_note_transform(0, Note());
   Transform::ToggleRest toggle_rest_transform;
   Transform::Retrograde retrograde_transform;

   transform_stack.add_transform(&insert_note_transform);
   transform_stack.add_transform(&toggle_rest_transform);
   transform_stack.add_transform(&retrograde_transform);

   std::vector<Transform::Base *> transforms = transform_stack.get_transformations();

   EXPECT_EQ(3, transforms.size());
   EXPECT_EQ("insert_note", transforms[0]->get_identifier());
   EXPECT_EQ("toggle_rest", transforms[1]->get_identifier());
   EXPECT_EQ("retrograde", transforms[2]->get_identifier());
}



TEST(TransformStackTest, returns_true_if_it_includes_a_reference)
{
   Transform::Stack transform_stack;

   Transform::Reference reference_transform(nullptr, 0, 0);

   transform_stack.add_transform(&reference_transform);

   EXPECT_EQ(true, transform_stack.includes_reference());
}



TEST(TransformStackTest, returns_false_if_it_does_not_include_a_reference)
{
   Transform::Stack transform_stack;

   EXPECT_EQ(false, transform_stack.includes_reference());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



