


#include <gtest/gtest.h>

#include <fullscore/models/measure.h>

#include <fullscore/transforms/insert_note.h>
#include <fullscore/transforms/stack.h>



TEST(MeasureTest, can_be_created)
{
   Measure measure;
}



TEST(MeasureTest, has_a_default_extension_of_12)
{
   Measure measure;
   ASSERT_EQ(12, measure.extension);
}



TEST(MeasureTest, with_genesis_populates_its_notes)
{
   Measure measure;

   measure.genesis = new Transform::Stack();
   Transform::InsertNote insert_note_transform(0, Note());
   for (unsigned i=0; i<3; i++) measure.genesis->add_transform(&insert_note_transform);

   ASSERT_EQ(true, measure.refresh());

   std::vector<Note> expected_notes = { Note(), Note(), Note() };
   std::vector<Note> measure_notes = measure.notes;

   ASSERT_EQ(expected_notes, measure_notes);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



