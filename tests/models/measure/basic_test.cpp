


#include <gtest/gtest.h>

#include <fullscore/models/measures/basic.h>



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



