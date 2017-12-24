


#include <gtest/gtest.h>



#include <fullscore/models/plotters/Destination.h>

#include <fullscore/models/measures/Base.h>
#include <fullscore/models/staves/MeasureNumbers.h>
#include <fullscore/models/Grid.h>



TEST(Plotter_DestinationTest, can_be_constructed_with_an_empty_constructor)
{
   Plotter::Destination plotter;

   std::vector<GridCoordinate> expected_destinations = { /* empty */ };

   ASSERT_EQ(expected_destinations, plotter.get_destinations());
}



TEST(Plotter_DestinationTest, can_add_and_check_presence_of_destination)
{
   Plotter::Destination plotter;
   GridCoordinate grid_coordinate_A(1, GridHorizontalCoordinate{5, 7});
   GridCoordinate grid_coordinate_B(2, GridHorizontalCoordinate{5, 7});

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_TRUE(plotter.has_destination(grid_coordinate_A));
   ASSERT_EQ(false, plotter.has_destination(grid_coordinate_B));
}



TEST(Plotter_DestinationTest, can_remove_a_destination)
{
   Plotter::Destination plotter;
   GridCoordinate grid_coordinate_A;

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_TRUE(plotter.remove_destination(grid_coordinate_A));

   std::vector<GridCoordinate> expected_destinations = { /* empty */ };
   std::vector<GridCoordinate> destinations = plotter.get_destinations();
}



TEST(Plotter_DestinationTest, returns_false_when_attempting_to_remove_a_destination_that_is_not_present)
{
   Plotter::Destination plotter;
   GridCoordinate grid_coordinate_A(1, GridHorizontalCoordinate{5, 7});

   ASSERT_FALSE(plotter.remove_destination(grid_coordinate_A));
}



TEST(Plotter_DestinationTest, returns_a_list_of_destinations)
{
   Plotter::Destination plotter;
   GridCoordinate grid_coordinate_A(0, GridHorizontalCoordinate{5, 7});
   GridCoordinate grid_coordinate_B(1, GridHorizontalCoordinate{5, 7});
   GridCoordinate grid_coordinate_C(2, GridHorizontalCoordinate{5, 7});

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_TRUE(plotter.add_destination(grid_coordinate_B));
   ASSERT_TRUE(plotter.add_destination(grid_coordinate_C));

   std::vector<GridCoordinate> expected_destinations = { grid_coordinate_A, grid_coordinate_B, grid_coordinate_C };
   std::vector<GridCoordinate> destinations = plotter.get_destinations();

   ASSERT_EQ(expected_destinations, destinations);
}



TEST(Plotter_DestinationTest, returns_the_number_of_destinations)
{
   Plotter::Destination plotter;
   GridCoordinate grid_coordinate_A(0, GridHorizontalCoordinate{5, 7});
   GridCoordinate grid_coordinate_B(1, GridHorizontalCoordinate{5, 7});
   GridCoordinate grid_coordinate_C(2, GridHorizontalCoordinate{5, 7});

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_EQ(1, plotter.num_destinations());

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_B));
   ASSERT_EQ(2, plotter.num_destinations());

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_C));
   ASSERT_EQ(3, plotter.num_destinations());

   ASSERT_TRUE(plotter.remove_destination(grid_coordinate_C));
   ASSERT_EQ(2, plotter.num_destinations());
}



TEST(Plotter_DestinationTest, cannot_add_a_destination_that_already_exists)
{
   Plotter::Destination plotter;
   GridCoordinate grid_coordinate_A(0, GridHorizontalCoordinate{5, 7});

   ASSERT_TRUE(plotter.add_destination(grid_coordinate_A));
   ASSERT_FALSE(plotter.add_destination(grid_coordinate_A));

   std::vector<GridCoordinate> expected_destinations = { grid_coordinate_A };
   std::vector<GridCoordinate> destinations = plotter.get_destinations();

   ASSERT_EQ(expected_destinations, destinations);
}



TEST(Plotter_DestinationTest, DISABLED_plots_plotted_measure_types_into_the_grid)
{
   // skip
}



TEST(Plotter_DestinationTest, DISABLED_when_plotting_to_a_destination_staff_that_does_not_exist_raises_an_error)
{
   // currently disabled because the implementation uses the y_coordinate of the staff, and not the staff_id
}



TEST(Plotter_DestinationTest, DISABLED_when_plotter_cannot_add_a_plotted_measure_to_the_grid_raises_an_exception)
{
   // TODO
}



