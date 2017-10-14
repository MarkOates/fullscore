


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



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



