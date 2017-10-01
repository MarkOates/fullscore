


#include <gtest/gtest.h>

#include <fullscore/models/grid_coordinate.h>
#include <fullscore/models/grid.h>



TEST(GridCoordinate, can_be_constructed_with_no_arguments)
{
   GridCoordinate grid_coordinate;

   EXPECT_EQ(nullptr, grid_coordinate.get_grid());
   EXPECT_EQ(0, grid_coordinate.get_staff_id());
   EXPECT_EQ(0, grid_coordinate.get_measure_num());
   EXPECT_EQ(0, grid_coordinate.get_beat_num());
}



TEST(GridCoordinate, can_be_constructed_with_arguments)
{
   Grid grid(1, 1);
   GridCoordinate grid_coordinate(&grid, 6, 13, 42);

   EXPECT_EQ(&grid, grid_coordinate.get_grid());
   EXPECT_EQ(6, grid_coordinate.get_staff_id());
   EXPECT_EQ(13, grid_coordinate.get_measure_num());
   EXPECT_EQ(42, grid_coordinate.get_beat_num());
}



TEST(GridCoordinate, gets_and_sets_the_grid)
{
   GridCoordinate grid_coordinate;

   Grid grid(1, 1);

   grid_coordinate.set_grid(&grid);
   EXPECT_EQ(&grid, grid_coordinate.get_grid());
}



TEST(GridCoordinate, gets_and_sets_the_staff_id)
{
   GridCoordinate grid_coordinate;

   grid_coordinate.set_staff_id(42);
   EXPECT_EQ(42, grid_coordinate.get_staff_id());
}



TEST(GridCoordinate, gets_and_sets_the_measure_num)
{
   GridCoordinate grid_coordinate;

   grid_coordinate.set_measure_num(123);
   EXPECT_EQ(123, grid_coordinate.get_measure_num());

   grid_coordinate.set_measure_num(-86);
   EXPECT_EQ(-86, grid_coordinate.get_measure_num());

   grid_coordinate.set_measure_num(720782);
   EXPECT_EQ(720782, grid_coordinate.get_measure_num());
}



TEST(GridCoordinate, gets_and_sets_the_beat_num)
{
   GridCoordinate grid_coordinate;

   grid_coordinate.set_beat_num(123);
   EXPECT_EQ(123, grid_coordinate.get_beat_num());

   grid_coordinate.set_beat_num(-86);
   EXPECT_EQ(-86, grid_coordinate.get_beat_num());

   grid_coordinate.set_beat_num(720782);
   EXPECT_EQ(720782, grid_coordinate.get_beat_num());
}



TEST(GridCoordinate, compares_equality_with_another_grid_coordinate)
{
   EXPECT_EQ(
      GridCoordinate(nullptr, 67, 195, 84),
      GridCoordinate(nullptr, 67, 195, 84)
   );

   EXPECT_NE(
      GridCoordinate(nullptr, 67, 195, 84),
      GridCoordinate(nullptr, 0,  195, 84)
   );

   EXPECT_NE(
      GridCoordinate(nullptr, 67, 195, 84),
      GridCoordinate(nullptr, 67, 0,   84)
   );

   EXPECT_NE(
      GridCoordinate(nullptr, 67, 195, 84),
      GridCoordinate(nullptr, 67, 195, 0)
   );
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



