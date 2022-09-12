


#include <gtest/gtest.h>

#include <fullscore/transforms/StackTransform.hpp>

#include <fullscore/transforms/InsertNoteTransform.hpp>
#include <fullscore/transforms/RetrogradeTransform.hpp>
#include <fullscore/transforms/ToggleRestTransform.hpp>
#include <fullscore/TransformNames.hpp>



TEST(TransformStackTest, can_be_created)
{
   Transform::Stack transform_stack;
}



TEST(TransformStackTest, has_an_identifier_of_stack)
{
   Transform::Stack transform_stack;
   EXPECT_EQ(TransformNames::STACK_TRANSFORM_IDENTIFIER, transform_stack.get_identifier());
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
   EXPECT_EQ(TransformNames::INSERT_NOTE_TRANSFORM_IDENTIFIER, transforms[0]->get_identifier());
   EXPECT_EQ(TransformNames::TOGGLE_REST_TRANSFORM_IDENTIFIER, transforms[1]->get_identifier());
   EXPECT_EQ(TransformNames::RETROGRADE_TRANSFORM_IDENTIFIER, transforms[2]->get_identifier());
}



