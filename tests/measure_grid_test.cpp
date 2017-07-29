


#include <gtest/gtest.h>

#include <fullscore/models/measure_grid.h>
#include <fullscore/models/note.h>



TEST(MeasureGridTest, creates_successfully)
{
   MeasureGrid measure_grid(1, 1);
}



TEST(MeasureGridTest, returns_the_number_of_staves)
{
   MeasureGrid measure_grid(17, 13);
   EXPECT_EQ(13, measure_grid.get_num_staves());
}



TEST(MeasureGridTest, returns_the_number_of_measures)
{
   MeasureGrid measure_grid(17, 3);
   EXPECT_EQ(17, measure_grid.get_num_measures());
}



TEST(MeasureGridTest, sets_and_gets_the_name_of_a_row)
{
   MeasureGrid measure_grid(1, 3);

   EXPECT_EQ(true, measure_grid.set_voice_name(0, "Trombone"));
   EXPECT_EQ("Trombone", measure_grid.get_voice_name(0));

   EXPECT_EQ(true, measure_grid.set_voice_name(2, "Euphonium"));
   EXPECT_EQ("Euphonium", measure_grid.get_voice_name(2));

   EXPECT_EQ(true, measure_grid.set_voice_name(2, "Tuba"));
   EXPECT_EQ("Tuba", measure_grid.get_voice_name(2));
}



TEST(MeasureGridTest, sets_and_gets_a_measure_to_a_coordinate)
{
   MeasureGrid measure_grid(17, 13);

   Measure::Basic *basic_measure = new Measure::Basic();

   EXPECT_TRUE(measure_grid.set_measure(3, 7, basic_measure));

   Measure::Base *retrieved_measure = measure_grid.get_measure(3, 7);
   ASSERT_NE(nullptr, retrieved_measure);
   ASSERT_TRUE(retrieved_measure->is_type(MEASURE_TYPE_IDENTIFIER_BASIC));

   int expected_id = basic_measure->get_id();
   int returned_id = retrieved_measure->get_id();

   EXPECT_EQ(expected_id, returned_id);
}



TEST(MeasureGridTest, can_delete_a_measure)
{
   MeasureGrid measure_grid(17, 13);

   Measure::Basic *basic_measure = new Measure::Basic();
   EXPECT_TRUE(measure_grid.set_measure(3, 7, basic_measure));

   Measure::Base *retrieved_measure = measure_grid.get_measure(3, 7);
   ASSERT_NE(nullptr, retrieved_measure);

   measure_grid.delete_measure(3, 7);

   Measure::Base  *expected_null_retrieved_measure = measure_grid.get_measure(3, 7);
   ASSERT_EQ(nullptr, expected_null_retrieved_measure);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



