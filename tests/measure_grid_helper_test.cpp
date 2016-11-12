



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




int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}





