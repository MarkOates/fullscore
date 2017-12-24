


#include <gtest/gtest.h>

#include <fullscore/models/Measure.h>
#include <fullscore/models/measures/Basic.h>



TEST(MeasureTest, can_find_a_measure_by_id)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   ASSERT_EQ(&basic_measure_1, Measure::find(basic_measure_1.get_id()));
   ASSERT_EQ(&basic_measure_2, Measure::find(basic_measure_2.get_id()));
}



TEST(MeasureTest, with_a_measure_id_that_is_not_found_returns_nullptr)
{
   ASSERT_EQ(nullptr, Measure::find(-1));
   ASSERT_EQ(nullptr, Measure::find(99999));
}



TEST(MeasureTest, with_a_measure_id_that_is_not_found_raises_an_exception__if_the_option_is_set)
{
   ASSERT_THROW(Measure::find(-1, Measure::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
   ASSERT_THROW(Measure::find(99999, Measure::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
}



TEST(MeasureTest, can_find_multiple_measures_by_id)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), basic_measure_3.get_id() };
   std::vector<Measure::Base *> expected_returned_measures = { &basic_measure_1, &basic_measure_3 };

   ASSERT_EQ(expected_returned_measures, Measure::find(measure_ids_to_find));
}



TEST(MeasureTest, with_a_measure_id_in_a_list_not_found_does_not_include_it_in_the_response_by_default)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), -1, basic_measure_2.get_id(), -2 };
   std::vector<Measure::Base *> expected_returned_measures = { &basic_measure_1, &basic_measure_2 };

   ASSERT_EQ(expected_returned_measures, Measure::find(measure_ids_to_find));
}



TEST(MeasureTest, with_a_measure_id_in_a_list_not_found_does_include_it_in_the_response_if_the_option_is_set)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), -1, basic_measure_2.get_id(), -2 };
   std::vector<Measure::Base *> expected_returned_measures = { &basic_measure_1, nullptr, &basic_measure_2, nullptr };

   ASSERT_EQ(expected_returned_measures, Measure::find(measure_ids_to_find, Measure::FIND_OPTION_INCLUDE_NOT_FOUND));
}



TEST(MeasureTest, with_a_measure_id_in_a_list_not_found_raises_an_exception_if_the_option_is_set)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), basic_measure_2.get_id(), -1 };

   ASSERT_THROW(Measure::find(measure_ids_to_find, Measure::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
}



TEST(MeasureTest, DISABLED_has_pool_functions)
{
   // these tests need to be added
}



