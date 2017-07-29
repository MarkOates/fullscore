


#include <gtest/gtest.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/measure.h>
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
   ASSERT_TRUE(retrieved_measure->is_type(Measure::TYPE_IDENTIFIER_BASIC));

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



TEST(MeasureGridTest, returns_true_if_coordinates_are_within_the_measure_grid)
{
   MeasureGrid measure_grid(17, 13);

   ASSERT_EQ(true, measure_grid.in_grid_range(0, 0));
   ASSERT_EQ(true, measure_grid.in_grid_range(0, 0));
   ASSERT_EQ(true, measure_grid.in_grid_range(measure_grid.get_num_measures()-1, 0));
   ASSERT_EQ(true, measure_grid.in_grid_range(0, measure_grid.get_num_staves()-1));
}



TEST(MeasureGridTest, returns_false_if_coordinates_are_outside_the_measure_grid)
{
   MeasureGrid measure_grid(17, 13);

   ASSERT_EQ(false, measure_grid.in_grid_range(-1, 0));
   ASSERT_EQ(false, measure_grid.in_grid_range(0, -1));
   ASSERT_EQ(false, measure_grid.in_grid_range(measure_grid.get_num_measures(), 0));
   ASSERT_EQ(false, measure_grid.in_grid_range(0, measure_grid.get_num_staves()));
}



TEST(MeasureGridTest, can_insert_a_staff)
{
   MeasureGrid measure_grid(1, 3);

   measure_grid.set_voice_name(0, "voice 0");
   measure_grid.set_voice_name(1, "voice 1");
   measure_grid.set_voice_name(2, "voice 2");

   measure_grid.insert_staff(1);
   measure_grid.set_voice_name(1, "inserted voice 1");

   measure_grid.insert_staff(3);
   measure_grid.set_voice_name(3, "inserted voice 2");

   std::vector<std::string> expected_voice_name_order = {
      "voice 0",
      "inserted voice 1",
      "voice 1",
      "inserted voice 2",
      "voice 2",
   };

   ASSERT_EQ(expected_voice_name_order.size(), measure_grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], measure_grid.get_voice_name(i));
}



TEST(MeasureGridTest, when_inserting_a_staff_at_index_lt_zero_inserts_at_the_begingging)
{
   MeasureGrid measure_grid(1, 2);

   measure_grid.set_voice_name(0, "voice 0");
   measure_grid.set_voice_name(1, "voice 1");

   measure_grid.insert_staff(100);

   std::vector<std::string> expected_voice_name_order = { "voice 0", "voice 1", "" };

   ASSERT_EQ(expected_voice_name_order.size(), measure_grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], measure_grid.get_voice_name(i));
}



TEST(MeasureGridTest, when_inserting_a_staff_at_index_gt_the_number_of_staves_appends_to_the_end)
{
   MeasureGrid measure_grid(1, 2);

   measure_grid.set_voice_name(0, "voice 0");
   measure_grid.set_voice_name(1, "voice 1");

   measure_grid.insert_staff(-100);

   std::vector<std::string> expected_voice_name_order = { "", "voice 0", "voice 1" };

   ASSERT_EQ(expected_voice_name_order.size(), measure_grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], measure_grid.get_voice_name(i));
}



TEST(MeasureGridTest, can_delete_staff)
{
   // skip
}



TEST(MeasureGridTest, can_append_a_staff)
{
   // skip
}



TEST(MeasureGridTest, can_insert_a_measure)
{
   // skip
}



TEST(MeasureGridTest, can_delete_measure)
{
   // skip
}



TEST(MeasureGridTest, can_append_a_measure)
{
   // skip
}



TEST(MeasureGridTest, can_get_and_set_a_time_signature)
{
   // skip
}



TEST(MeasureGridTest, can_get_a_pointer_to_a_time_signature)
{
   // skip
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



