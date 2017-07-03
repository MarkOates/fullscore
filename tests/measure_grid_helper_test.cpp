



#include <gtest/gtest.h>

#include <fullscore/helpers/measure_grid_helper.h>
#include <fullscore/models/measure_grid.h>
#include <fullscore/models/note.h>




TEST(MeasureGridHelperTest, returns_the_length_to_the_measure_of_4_4_measures)
{
   MeasureGrid measure_grid(10, 1);
   EXPECT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 0), 0.0);
   EXPECT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 1), 1.0);
   EXPECT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 2), 2.0);
   EXPECT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 9), 9.0);
}




TEST(MeasureGridHelperTest, returns_the_length_to_the_end_of_the_grid_when_measure_index_is_gt_total_measures)
{
   MeasureGrid measure_grid(10, 1);
   EXPECT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 10), 10.0);
   EXPECT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 11), 10.0);
   EXPECT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 9999), 10.0);
}




TEST(MeasureGridHelperTest, returns_the_length_to_the_measure_with_non_4_4_time_signatures)
{
   int measure_num = 0;
   float expected_length = 0;
   MeasureGrid measure_grid(10, 1);

   measure_grid.set_time_signature(0, TimeSignature(3, Duration(4, 0)));
   measure_grid.set_time_signature(1, TimeSignature(5, Duration(4, 0)));
   measure_grid.set_time_signature(2, TimeSignature(6, Duration(8, 0)));
   measure_grid.set_time_signature(3, TimeSignature(5, Duration(16, 0)));
   measure_grid.set_time_signature(4, TimeSignature(5, Duration(2, 0)));
   measure_grid.set_time_signature(5, TimeSignature(9, Duration(8, 0)));

   ASSERT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 1), 0.75);
   ASSERT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 2), 2.0);
   ASSERT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 3), 2.75);
   ASSERT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 4), 3.0625); // + 0.3125
   ASSERT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 5), 5.5625); // + 2.5
   ASSERT_EQ(MeasureGridHelper::get_length_to_measure(measure_grid, 6), 6.6875); // + 1.125
}




int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}





