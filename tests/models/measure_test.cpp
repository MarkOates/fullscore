


#include <gtest/gtest.h>

#include <fullscore/models/measure.h>
#include <fullscore/models/measures/basic.h>



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
   ASSERT_THROW(Measure::find(-1, true), std::runtime_error);
   ASSERT_THROW(Measure::find(99999, true), std::runtime_error);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



