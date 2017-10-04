


#include <gtest/gtest.h>



#include <fullscore/models/plotters/base.h>

#include <fullscore/models/measures/base.h>
#include <fullscore/models/staves/measure_numbers.h>
#include <fullscore/models/grid.h>



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



TEST(PlotterTest, plots_plotted_measure_types_into_the_grid)
{
   Grid grid(10, 10);
   Plotter plotter;

   std::vector<GridCoordinate> destinations = {
      GridCoordinate(&grid, 0, 4, 0),
      GridCoordinate(&grid, 1, 7, 0),
      GridCoordinate(&grid, 2, 9, 0)
   };

   for (auto &destination : destinations) ASSERT_TRUE(plotter.add_destination(destination));

   ASSERT_TRUE(plotter.plot());

   for (auto &destination : destinations)
   {
      int staff_id = destination.get_staff_id();
      int measure_number = destination.get_measure_num();
      // int beat_number = destination.beat_number(); // < not yet implemented

      Measure::Base *measure = grid.get_measure(measure_number, staff_id);
      ASSERT_NE(nullptr, measure);
      ASSERT_TRUE(measure->is_type("plotted"));
   }
}



TEST(PlotterTest, when_plotting_to_a_nullptr_destination_grid_raises_an_error)
{
   Plotter plotter;
   GridCoordinate grid_coordinate(nullptr, 0, 0, 0);

   ASSERT_TRUE(plotter.add_destination(grid_coordinate));

   ASSERT_THROW(plotter.plot(), std::runtime_error);
}



TEST(PlotterTest, when_plotting_to_a_destination_staff_that_is_not_an_instrument_type_raises_an_error)
{
   Grid grid(1, 0);
   grid.append_staff(new Staff::MeasureNumbers(1));

   Plotter plotter;
   GridCoordinate grid_coordinate(&grid, 0, 0, 0);

   ASSERT_TRUE(plotter.add_destination(grid_coordinate));

   ASSERT_THROW(plotter.plot(), std::runtime_error);
}



TEST(PlotterTest, DISABLED_when_plotting_to_a_destination_staff_that_does_not_exist_raises_an_error)
{
   // currently disabled because the implementation uses the y_coordinate of the staff, and not the staff_id
}



TEST(PlotterTest, DISABLED_when_plotter_cannot_add_a_plotted_measure_to_the_grid_raises_an_exception)
{
   // TODO
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



