


#include <gtest/gtest.h>

#include <fullscore/models/duration.h>



TEST(DurationTest, can_be_created)
{
   Duration duration(Duration::HALF, 0);
}



TEST(DurationTest, equality_operator_returns_true_on_equal_durations)
{
   EXPECT_EQ(true, Duration(Duration::HALF, 0).operator==(Duration(Duration::HALF, 0)));
   EXPECT_EQ(true, Duration(Duration::HALF, 1).operator==(Duration(Duration::HALF, 1)));
   EXPECT_EQ(true, Duration(Duration::QUARTER, 1).operator==(Duration(Duration::QUARTER, 1)));
}



TEST(DurationTest, equality_operator_returns_false_on_unequal_durations)
{
   EXPECT_EQ(false, Duration(Duration::QUARTER, 0).operator==(Duration(Duration::HALF, 0)));
   EXPECT_EQ(false, Duration(Duration::HALF, 0).operator==(Duration(Duration::HALF, 1)));
   EXPECT_EQ(false, Duration(Duration::EIGHTH, 1).operator==(Duration(Duration::QUARTER, 2)));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



