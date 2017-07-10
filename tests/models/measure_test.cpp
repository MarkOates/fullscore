


#include <gtest/gtest.h>

#include <fullscore/models/measure.h>



TEST(MeasureTest, can_be_created)
{
   Measure measure;
}



TEST(MeasureTest, has_a_default_extension_of_12)
{
   Measure measure;
   ASSERT_EQ(12, measure.extension);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



