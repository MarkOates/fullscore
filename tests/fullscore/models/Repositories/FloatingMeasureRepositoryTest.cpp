


#include <gtest/gtest.h>

#include <fullscore/models/Repositories/FloatingMeasureRepository.hpp>

#include <fullscore/models/measures/Basic.hpp>



TEST(FloatingMeasureRepositoryTest, can_be_created)
{
   FloatingMeasureRepository floating_measure(GridCoordinate(), 0);
}



TEST(FloatingMeasureRepositoryTest, returns_its_measure_id)
{
   FloatingMeasureRepository floating_measure(GridCoordinate(), 1234);

   ASSERT_EQ(1234, floating_measure.get_measure_id());
}



TEST(FloatingMeasureRepositoryTest, returns_its_grid_coordinate)
{
   GridCoordinate grid_coordinate(7, GridHorizontalCoordinate{11, 3});
   FloatingMeasureRepository floating_measure(grid_coordinate, 0);

   ASSERT_EQ(grid_coordinate, floating_measure.get_grid_coordinate());
}



TEST(FloatingMeasureRepositoryTest, is_assigned_an_incremented_id_when_created)
{
   int next_id = FloatingMeasureRepository::get_next_id();

   FloatingMeasureRepository floating_measure_1(GridCoordinate(), 0);
   FloatingMeasureRepository floating_measure_2(GridCoordinate(), 0);
   FloatingMeasureRepository floating_measure_3(GridCoordinate(), 0);

   ASSERT_EQ(next_id + 0, floating_measure_1.get_id());
   ASSERT_EQ(next_id + 1, floating_measure_2.get_id());
   ASSERT_EQ(next_id + 2, floating_measure_3.get_id());
}



TEST(FloatingMeasureRepositoryTest, can_find_a_floating_measure_by_id)
{
   FloatingMeasureRepository floating_measure_1(GridCoordinate(), 0);
   FloatingMeasureRepository floating_measure_2(GridCoordinate(), 0);
   FloatingMeasureRepository floating_measure_3(GridCoordinate(), 0);

   ASSERT_EQ(&floating_measure_1, FloatingMeasureRepository::find(floating_measure_1.get_id()));
   ASSERT_EQ(&floating_measure_2, FloatingMeasureRepository::find(floating_measure_2.get_id()));
   ASSERT_EQ(&floating_measure_3, FloatingMeasureRepository::find(floating_measure_3.get_id()));
}



TEST(FloatingMeasureRepositoryTest, can_find_measures_given_a_staff_id_and_a_barline)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   FloatingMeasureRepository floating_measure_1(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_2(GridCoordinate(7, 2), basic_measure_2.get_id());
   FloatingMeasureRepository floating_measure_3(GridCoordinate(7, 0), basic_measure_3.get_id());

   std::vector<FloatingMeasureRepository *> expected_measures = { &floating_measure_2 };

   ASSERT_EQ(expected_measures, FloatingMeasureRepository::find_at_staff_and_barline(7, 2));
}



TEST(FloatingMeasureRepositoryTest, can_find_measures_given_a_staff_id_and_after_a_barline)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   FloatingMeasureRepository floating_measure_1(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_2(GridCoordinate(7, 3), basic_measure_2.get_id());
   FloatingMeasureRepository floating_measure_3(GridCoordinate(7, 0), basic_measure_3.get_id());
   FloatingMeasureRepository floating_measure_4(GridCoordinate(7, 2), basic_measure_2.get_id());

   std::vector<FloatingMeasureRepository *> expected_measures = { &floating_measure_4, &floating_measure_2 };

   ASSERT_EQ(expected_measures, FloatingMeasureRepository::find_in_staff_after_barline(7, 2));
}



TEST(FloatingMeasureRepositoryTest, can_find_first_floating_measure_at_staff_id_and_after_a_barline)
{
   Measure::Basic basic_measure_1;

   FloatingMeasureRepository floating_measure_1(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_2(GridCoordinate(7, 3), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_3(GridCoordinate(7, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_4(GridCoordinate(7, 2), basic_measure_1.get_id());

   ASSERT_EQ(&floating_measure_4, FloatingMeasureRepository::find_first_in_staff_after_barline(7, 1));
   ASSERT_EQ(&floating_measure_1, FloatingMeasureRepository::find_first_in_staff_after_barline(3, 0));
}



TEST(FloatingMeasureRepositoryTest, returns_nullptr_when_cannot_find_first_floating_measure_at_staff_id_and_at_and_after_a_barline)
{
   Measure::Basic basic_measure_1;

   FloatingMeasureRepository floating_measure_1(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_2(GridCoordinate(7, 3), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_3(GridCoordinate(7, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_4(GridCoordinate(7, 2), basic_measure_1.get_id());

   ASSERT_EQ(nullptr, FloatingMeasureRepository::find_first_in_staff_after_barline(7, 4));
   ASSERT_EQ(nullptr, FloatingMeasureRepository::find_first_in_staff_after_barline(999, 0));
}



TEST(FloatingMeasureRepositoryTest, can_get_a_list_of_floating_measures)
{
   FloatingMeasureRepository::destroy_all();

   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   FloatingMeasureRepository floating_measure_1(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_2(GridCoordinate(7, 2), basic_measure_2.get_id());
   FloatingMeasureRepository floating_measure_3(GridCoordinate(7, 0), basic_measure_3.get_id());

   std::vector<FloatingMeasureRepository *> expected_measures = {
      &floating_measure_1,
      &floating_measure_2,
      &floating_measure_3
   };

   ASSERT_EQ(expected_measures, FloatingMeasureRepository::get_pool_elements());
}



TEST(FloatingMeasureRepositoryTest, can_get_a_list_of_floating_measures_for_a_staff)
{
   FloatingMeasureRepository::destroy_all();

   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   FloatingMeasureRepository floating_measure_1(GridCoordinate(3, 1), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_2(GridCoordinate(7, 2), basic_measure_2.get_id());
   FloatingMeasureRepository floating_measure_3(GridCoordinate(3, 0), basic_measure_1.get_id());
   FloatingMeasureRepository floating_measure_4(GridCoordinate(7, 0), basic_measure_3.get_id());
   FloatingMeasureRepository floating_measure_5(GridCoordinate(7, 9), basic_measure_3.get_id());

   std::vector<FloatingMeasureRepository *> expected_measures_in_staff_3 = {
      &floating_measure_3,
      &floating_measure_1
   };

   std::vector<FloatingMeasureRepository *> expected_measures_in_staff_7 = {
      &floating_measure_4,
      &floating_measure_2,
      &floating_measure_5 // note the sorting order
   };

   ASSERT_EQ(expected_measures_in_staff_3, FloatingMeasureRepository::find_in_staff(3));
   ASSERT_EQ(expected_measures_in_staff_7, FloatingMeasureRepository::find_in_staff(7));
}



TEST(FloatingMeasureRepositoryTest, returns_a_staffs_floating_measures_horizontally_sorted_by_default)
{
   FloatingMeasureRepository::destroy_all();

   FloatingMeasureRepository floating_measure_1(GridCoordinate(0, 3), 0);
   FloatingMeasureRepository floating_measure_2(GridCoordinate(0, 1), 0);
   FloatingMeasureRepository floating_measure_3(GridCoordinate(0, {2, {3, 8}}), 0);
   FloatingMeasureRepository floating_measure_4(GridCoordinate(0, {2, {3, 8}}), 0);
   FloatingMeasureRepository floating_measure_5(GridCoordinate(0, {3, {2, 4}}), 0);
   FloatingMeasureRepository floating_measure_6(GridCoordinate(0, {2, {2, 4}}), 0);
   FloatingMeasureRepository floating_measure_7(GridCoordinate(0, {1, {3, 8}}), 0);

   std::vector<FloatingMeasureRepository *> expected_measures_order = {
      &floating_measure_2,
      &floating_measure_7,
      &floating_measure_6,
      &floating_measure_3,
      &floating_measure_4,
      &floating_measure_1,
      &floating_measure_5
   };

   ASSERT_EQ(expected_measures_order, FloatingMeasureRepository::find_in_staff(0));
}



TEST(FloatingMeasureRepositoryTest, DISABLED_returns_a_staffs_floating_measures_with_undefined_sorting)
{
   // test not necessary
}



TEST(FloatingMeasureRepositoryTest, can_get_the_number_of_floating_measures_in_the_pool)
{
   Measure::Basic basic_measure;

   int initial_num_pool_elements = FloatingMeasureRepository::get_num_pool_elements();
   int expected_num_pool_elements = initial_num_pool_elements;

   FloatingMeasureRepository floating_measure_1({}, basic_measure.get_id());

   expected_num_pool_elements++;

   ASSERT_EQ(expected_num_pool_elements, FloatingMeasureRepository::get_num_pool_elements());

   FloatingMeasureRepository floating_measure_2({}, basic_measure.get_id());

   expected_num_pool_elements++;

   ASSERT_EQ(expected_num_pool_elements, FloatingMeasureRepository::get_num_pool_elements());

   FloatingMeasureRepository floating_measure_3({}, basic_measure.get_id());

   expected_num_pool_elements++;

   ASSERT_EQ(expected_num_pool_elements, FloatingMeasureRepository::get_num_pool_elements());
}



TEST(FloatingMeasureRepositoryTest, DISABLED_has_pool_functions)
{
   // these tests need to be added
}



