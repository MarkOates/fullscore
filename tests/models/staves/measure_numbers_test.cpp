


#include <gtest/gtest.h>

#include <fullscore/models/staves/measure_numbers.h>



TEST(Staff_MeasureNumbersTest, can_be_created)
{
   Staff::MeasureNumbers measure_numbers(1);
}



TEST(Staff_MeasureNumbersTest, returns_a_staff_height_of_0_75)
{
   Staff::MeasureNumbers measure_numbers(1);

   ASSERT_EQ(0.75, measure_numbers.get_height());
}



TEST(Staff_MeasureNumbersTest, returns_the_number_of_measures_or_columns)
{
   Staff::MeasureNumbers measure_numbers(37);

   ASSERT_EQ(37, measure_numbers.get_num_columns());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



