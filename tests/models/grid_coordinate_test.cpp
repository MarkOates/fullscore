


#include <gtest/gtest.h>

#include <fullscore/models/grid_coordinate.h>
#include <fullscore/models/grid.h>



TEST(GridCoordinate, can_be_constructed_with_no_arguments)
{
   GridCoordinate grid_coordinate;

   EXPECT_EQ(0, grid_coordinate.get_staff_id());
   EXPECT_EQ(0, grid_coordinate.get_barline_num());
   EXPECT_EQ(0, grid_coordinate.get_beat_num());
}



TEST(GridCoordinate, can_be_constructed_with_arguments)
{
   GridHorizontalCoordinate grid_horizontal_coordinate{13, 42};
   GridCoordinate grid_coordinate(6, grid_horizontal_coordinate);

   EXPECT_EQ(6, grid_coordinate.get_staff_id());
   EXPECT_EQ(grid_horizontal_coordinate, grid_coordinate.get_grid_horizontal_coordinate());
}



TEST(GridCoordinate, gets_and_sets_the_staff_id)
{
   GridCoordinate grid_coordinate;

   grid_coordinate.set_staff_id(42);
   EXPECT_EQ(42, grid_coordinate.get_staff_id());
}



TEST(GridCoordinate, gets_and_sets_the_grid_horizontal_coordinate)
{
   GridCoordinate grid_coordinate;


   GridHorizontalCoordinate grid_horizontal_coordinate_1{123};
   grid_coordinate.set_grid_horizontal_coordinate(grid_horizontal_coordinate_1);
   EXPECT_EQ(grid_horizontal_coordinate_1, grid_coordinate.get_grid_horizontal_coordinate());

   GridHorizontalCoordinate grid_horizontal_coordinate_2{-86};
   grid_coordinate.set_grid_horizontal_coordinate(grid_horizontal_coordinate_2);
   EXPECT_EQ(grid_horizontal_coordinate_2, grid_coordinate.get_grid_horizontal_coordinate());

   GridHorizontalCoordinate grid_horizontal_coordinate_3{720782};
   grid_coordinate.set_grid_horizontal_coordinate(grid_horizontal_coordinate_3);
   EXPECT_EQ(grid_horizontal_coordinate_3, grid_coordinate.get_grid_horizontal_coordinate());
}



TEST(GridCoordinate, compares_equality_with_another_grid_coordinate)
{
   EXPECT_EQ(
      GridCoordinate(67, GridHorizontalCoordinate{195, 84}),
      GridCoordinate(67, GridHorizontalCoordinate{195, 84})
   );

   EXPECT_NE(
      GridCoordinate(67, GridHorizontalCoordinate{195, 84}),
      GridCoordinate(0,  GridHorizontalCoordinate{195, 84})
   );

   EXPECT_NE(
      GridCoordinate(67, GridHorizontalCoordinate{195, 84}),
      GridCoordinate(67, GridHorizontalCoordinate{0,   84})
   );
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



