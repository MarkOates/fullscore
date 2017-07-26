


#include <gtest/gtest.h>

#include <fullscore/models/measures/basic.h>

#include <fullscore/transforms/insert_note_transform.h>
#include <fullscore/transforms/reference_transform.h>
#include <fullscore/transforms/stack_transform.h>



TEST(MeasureTest, can_be_created)
{
   Measure::Basic measure;
}



TEST(MeasureTest, has_a_default_extension_of_12)
{
   Measure::Basic measure;
   ASSERT_EQ(12, measure.extension);
}



TEST(MeasureTest, can_get_and_set_notes)
{
   Measure::Basic measure;
   std::vector<Note> expected_notes = { Note(2, Duration::HALF), Note(-1, Duration::EIGHTH), Note(14, Duration::QUARTER) };

   ASSERT_EQ(true, measure.set_notes(expected_notes));

   std::vector<Note> returned_notes = measure.get_notes_copy();

   ASSERT_EQ(3, returned_notes.size());
   ASSERT_EQ(expected_notes, returned_notes);
}



TEST(MeasureTest, with_genesis_populates_its_notes)
{
   Measure::Basic measure;

   measure.genesis = new Transform::Stack();
   Transform::InsertNote insert_note_transform(0, Note());
   for (unsigned i=0; i<3; i++) measure.genesis->add_transform(&insert_note_transform);

   ASSERT_EQ(true, measure.refresh());

   std::vector<Note> expected_notes = { Note(), Note(), Note() };
   std::vector<Note> measure_notes = measure.get_notes_copy();

   ASSERT_EQ(expected_notes, measure_notes);
}



TEST(MeasureTest, returns_true_if_references_a_source_in_its_genesis)
{
   Measure::Basic measure;

   measure.genesis = new Transform::Stack();
   Transform::Reference reference_transform(nullptr, 0, 0);
   measure.genesis->add_transform(&reference_transform);

   ASSERT_EQ(true, measure.references_source());
}



TEST(MeasureTest, returns_false_if_it_does_not_reference_a_source_in_its_genesis__test_1)
{
   Measure::Basic measure;
   ASSERT_EQ(false, measure.references_source());
}



TEST(MeasureTest, returns_false_if_it_does_not_reference_a_source_in_its_genesis__test_2)
{
   Measure::Basic measure;

   measure.genesis = new Transform::Stack();
   Transform::InsertNote insert_note_transform(0, Note());
   for (unsigned i=0; i<3; i++) measure.genesis->add_transform(&insert_note_transform);

   ASSERT_EQ(false, measure.references_source());
}



TEST(MeasureTest, can_get_its_number_of_notes)
{
   Measure::Basic measure1({ Note(0), Note(0), Note(0) });
   ASSERT_EQ(3, measure1.get_num_notes());

   Measure::Basic measure2({ Note(0), Note(0), Note(0), Note(0), Note(0), Note(0), Note(0) });
   ASSERT_EQ(7, measure2.get_num_notes());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



