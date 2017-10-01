


#include <gtest/gtest.h>

#include <fullscore/models/grid_horizontal_coordinate.h>



TEST(GridHorizontalCoordinate, can_be_created)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;
}



TEST(GridHorizontalCoordinate, gets_and_sets_the_measure_num)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;

   grid_horizontal_coordinate.set_measure_num(123);
   EXPECT_EQ(123, grid_horizontal_coordinate.get_measure_num());

   grid_horizontal_coordinate.set_measure_num(-86);
   EXPECT_EQ(-86, grid_horizontal_coordinate.get_measure_num());

   grid_horizontal_coordinate.set_measure_num(720782);
   EXPECT_EQ(720782, grid_horizontal_coordinate.get_measure_num());
}



TEST(GridHorizontalCoordinate, gets_and_sets_the_beat_num)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;

   grid_horizontal_coordinate.set_beat_num(123);
   EXPECT_EQ(123, grid_horizontal_coordinate.get_beat_num());

   grid_horizontal_coordinate.set_beat_num(-86);
   EXPECT_EQ(-86, grid_horizontal_coordinate.get_beat_num());

   grid_horizontal_coordinate.set_beat_num(720782);
   EXPECT_EQ(720782, grid_horizontal_coordinate.get_beat_num());
}



TEST(GridHorizontalCoordinate, on_construction_without_arguments_hasthe_expected_default_values)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;

   EXPECT_EQ(0, grid_horizontal_coordinate.get_measure_num());
   EXPECT_EQ(0, grid_horizontal_coordinate.get_beat_num());
}



TEST(GridHorizontalCoordinate, on_construction_with_arguments_initializes_the_expected_values)
{
   GridHorizontalCoordinate grid_horizontal_coordinate(98, 123);

   EXPECT_EQ(98, grid_horizontal_coordinate.get_measure_num());
   EXPECT_EQ(123, grid_horizontal_coordinate.get_beat_num());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



