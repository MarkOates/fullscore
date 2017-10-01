


#include <gtest/gtest.h>



#include <fullscore/models/plotter.h>



TEST(PlotterTest, can_be_constructed_with_an_empty_constructor)
{
   Plotter plotter;

   std::vector<GridCoordinate> expected_destinations = { /* empty */ };

   ASSERT_EQ(expected_destinations, plotter.get_destinations());
}



TEST(PlotterTest, can_add_and_check_presence_of_destination)
{
   Plotter plotter;
   GridCoordinate grid_coordinate_A(nullptr, 1, 5, 7);
   GridCoordinate grid_coordinate_B(nullptr, 2, 5, 7);

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_TRUE(plotter.has_destination(grid_coordinate_A));
   ASSERT_EQ(false, plotter.has_destination(grid_coordinate_B));
}



TEST(PlotterTest, can_remove_a_destination)
{
   Plotter plotter;
   GridCoordinate grid_coordinate_A;

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_TRUE(plotter.remove_destination(grid_coordinate_A));

   std::vector<GridCoordinate> expected_destinations = { /* empty */ };
   std::vector<GridCoordinate> destinations = plotter.get_destinations();
}



TEST(PlotterTest, returns_false_when_attempting_to_remove_a_destination_that_is_not_present)
{
   Plotter plotter;
   GridCoordinate grid_coordinate_A(nullptr, 1, 5, 7);

   ASSERT_FALSE(plotter.remove_destination(grid_coordinate_A));
}



TEST(PlotterTest, returns_a_list_of_destinations)
{
   Plotter plotter;
   GridCoordinate grid_coordinate_A(nullptr, 0, 5, 7);
   GridCoordinate grid_coordinate_B(nullptr, 1, 5, 7);
   GridCoordinate grid_coordinate_C(nullptr, 2, 5, 7);

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_TRUE(plotter.add_destination(grid_coordinate_B));
   ASSERT_TRUE(plotter.add_destination(grid_coordinate_C));

   std::vector<GridCoordinate> expected_destinations = { grid_coordinate_A, grid_coordinate_B, grid_coordinate_C };
   std::vector<GridCoordinate> destinations = plotter.get_destinations();

   ASSERT_EQ(expected_destinations, destinations);
}



TEST(PlotterTest, returns_the_number_of_destinations)
{
   Plotter plotter;
   GridCoordinate grid_coordinate_A(nullptr, 0, 5, 7);
   GridCoordinate grid_coordinate_B(nullptr, 1, 5, 7);
   GridCoordinate grid_coordinate_C(nullptr, 2, 5, 7);

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_EQ(1, plotter.num_destinations());

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_B));
   ASSERT_EQ(2, plotter.num_destinations());

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_C));
   ASSERT_EQ(3, plotter.num_destinations());

   ASSERT_TRUE(plotter.remove_destination(grid_coordinate_C));
   ASSERT_EQ(2, plotter.num_destinations());
}



TEST(PlotterTest, cannot_add_a_destination_that_already_exists)
{
   Plotter plotter;
   GridCoordinate grid_coordinate_A(nullptr, 0, 5, 7);

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_FALSE(plotter.add_destination(grid_coordinate_A));

   std::vector<GridCoordinate> expected_destinations = { grid_coordinate_A };
   std::vector<GridCoordinate> destinations = plotter.get_destinations();

   ASSERT_EQ(expected_destinations, destinations);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



