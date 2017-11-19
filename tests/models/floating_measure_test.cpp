


#include <gtest/gtest.h>

#include <fullscore/models/floating_measure.h>

#include <fullscore/models/measures/basic.h>



TEST(FloatingMeasureTest, can_be_created)
{
   FloatingMeasure floating_measure(GridCoordinate(), 0);
}



TEST(FloatingMeasureTest, returns_its_measure_id)
{
   FloatingMeasure floating_measure(GridCoordinate(), 1234);

   ASSERT_EQ(1234, floating_measure.get_measure_id());
}



TEST(FloatingMeasureTest, returns_its_grid_coordinate)
{
   GridCoordinate grid_coordinate(7, GridHorizontalCoordinate{11, 3});
   FloatingMeasure floating_measure(grid_coordinate, 0);

   ASSERT_EQ(grid_coordinate, floating_measure.get_grid_coordinate());
}



TEST(FloatingMeasureTest, is_assigned_an_incremented_id_when_created)
{
   int next_id = FloatingMeasure::get_next_id();

   FloatingMeasure floating_measure_1(GridCoordinate(), 0);
   FloatingMeasure floating_measure_2(GridCoordinate(), 0);
   FloatingMeasure floating_measure_3(GridCoordinate(), 0);

   ASSERT_EQ(next_id + 0, floating_measure_1.get_id());
   ASSERT_EQ(next_id + 1, floating_measure_2.get_id());
   ASSERT_EQ(next_id + 2, floating_measure_3.get_id());
}



TEST(FloatingMeasureTest, can_find_a_floating_measure_by_id)
{
   FloatingMeasure floating_measure_1(GridCoordinate(), 0);
   FloatingMeasure floating_measure_2(GridCoordinate(), 0);
   FloatingMeasure floating_measure_3(GridCoordinate(), 0);

   ASSERT_EQ(&floating_measure_1, FloatingMeasure::find(floating_measure_1.get_id()));
   ASSERT_EQ(&floating_measure_2, FloatingMeasure::find(floating_measure_2.get_id()));
   ASSERT_EQ(&floating_measure_3, FloatingMeasure::find(floating_measure_3.get_id()));
}



TEST(FloatingMeasureTest, can_find_measures_given_a_staff_id_and_a_barline)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   FloatingMeasure floating_measure_1(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasure floating_measure_2(GridCoordinate(7, 2), basic_measure_2.get_id());
   FloatingMeasure floating_measure_3(GridCoordinate(7, 0), basic_measure_3.get_id());

   std::vector<FloatingMeasure *> expected_measures = { &floating_measure_2 };

   ASSERT_EQ(expected_measures, FloatingMeasure::find_at_staff_and_barline(7, 2));
}



TEST(FloatingMeasureTest, can_get_a_list_of_floating_measures)
{
   FloatingMeasure::destroy_all();

   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   FloatingMeasure floating_measure_1(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasure floating_measure_2(GridCoordinate(7, 2), basic_measure_2.get_id());
   FloatingMeasure floating_measure_3(GridCoordinate(7, 0), basic_measure_3.get_id());

   std::vector<FloatingMeasure *> expected_measures = {
      &floating_measure_1,
      &floating_measure_2,
      &floating_measure_3
   };

   ASSERT_EQ(expected_measures, FloatingMeasure::get_pool_elements());
}



TEST(FloatingMeasureTest, can_get_a_list_of_floating_measures_for_a_staff)
{
   FloatingMeasure::destroy_all();

   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   FloatingMeasure floating_measure_1(GridCoordinate(3, 1), basic_measure_1.get_id());
   FloatingMeasure floating_measure_2(GridCoordinate(7, 2), basic_measure_2.get_id());
   FloatingMeasure floating_measure_3(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasure floating_measure_4(GridCoordinate(7, 0), basic_measure_3.get_id());
   FloatingMeasure floating_measure_5(GridCoordinate(7, 9), basic_measure_3.get_id());

   std::vector<FloatingMeasure *> expected_measures_in_staff_3 = {
      &floating_measure_3,
      &floating_measure_1
   };

   std::vector<FloatingMeasure *> expected_measures_in_staff_7 = {
      &floating_measure_4,
      &floating_measure_2,
      &floating_measure_5 // note the sorting order
   };

   ASSERT_EQ(expected_measures_in_staff_3, FloatingMeasure::in_staff(3));
   ASSERT_EQ(expected_measures_in_staff_7, FloatingMeasure::in_staff(7));
}



TEST(FloatingMeasureTest, can_get_the_number_of_floating_measures_in_the_pool)
{
   Measure::Basic basic_measure;

   int initial_num_pool_elements = FloatingMeasure::get_num_pool_elements();
   int expected_num_pool_elements = initial_num_pool_elements;

   FloatingMeasure floating_measure_1({}, basic_measure.get_id());

   expected_num_pool_elements++;

   ASSERT_EQ(expected_num_pool_elements, FloatingMeasure::get_num_pool_elements());

   FloatingMeasure floating_measure_2({}, basic_measure.get_id());

   expected_num_pool_elements++;

   ASSERT_EQ(expected_num_pool_elements, FloatingMeasure::get_num_pool_elements());

   FloatingMeasure floating_measure_3({}, basic_measure.get_id());

   expected_num_pool_elements++;

   ASSERT_EQ(expected_num_pool_elements, FloatingMeasure::get_num_pool_elements());
}



TEST(FloatingMeasureTest, DISABLED_has_pool_functions)
{
   // these tests need to be added
}



