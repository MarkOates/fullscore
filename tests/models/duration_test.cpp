


#include <gtest/gtest.h>

#include <fullscore/models/Duration.h>



TEST(DurationTest, can_be_created)
{
   Duration duration(Duration::HALF, 0);
}



TEST(DurationTest, equality_operator_returns_true_on_equal_durations)
{
   EXPECT_EQ(false, Duration(Duration::HALF, 0).operator==(Duration(Duration::HALF, 999)));
   EXPECT_EQ(false, Duration(Duration::HALF, 0).operator==(Duration(Duration::QUARTER, 0)));

   EXPECT_EQ(true, Duration(Duration::HALF, 0).operator==(Duration(Duration::HALF, 0)));
   EXPECT_EQ(true, Duration(Duration::HALF, 1).operator==(Duration(Duration::HALF, 1)));
   EXPECT_EQ(true, Duration(Duration::QUARTER, 1).operator==(Duration(Duration::QUARTER, 1)));
}



TEST(DurationTest, equality_operator_returns_false_on_unequal_durations)
{
   EXPECT_EQ(true, Duration(Duration::HALF, 0).operator!=(Duration(Duration::HALF, 999)));
   EXPECT_EQ(true, Duration(Duration::HALF, 0).operator!=(Duration(Duration::QUARTER, 0)));

   EXPECT_EQ(false, Duration(Duration::HALF, 0).operator!=(Duration(Duration::HALF, 0)));
   EXPECT_EQ(false, Duration(Duration::HALF, 1).operator!=(Duration(Duration::HALF, 1)));
   EXPECT_EQ(false, Duration(Duration::QUARTER, 1).operator!=(Duration(Duration::QUARTER, 1)));
}



TEST(DurationTest, halves_the_duration)
{
   EXPECT_EQ(Duration::SIXTYFOURTH, half_duration(Duration::THIRTYSECOND));
   EXPECT_EQ(Duration::THIRTYSECOND, half_duration(Duration::SIXTEENTH));
   EXPECT_EQ(Duration::SIXTEENTH, half_duration(Duration::EIGHTH));
   EXPECT_EQ(Duration::QUARTER, half_duration(Duration::HALF));
   EXPECT_EQ(Duration::HALF, half_duration(Duration::WHOLE));
}



TEST(DurationTest, doubles_the_duration)
{
   EXPECT_EQ(Duration::THIRTYSECOND, double_duration(Duration::SIXTYFOURTH));
   EXPECT_EQ(Duration::SIXTEENTH, double_duration(Duration::THIRTYSECOND));
   EXPECT_EQ(Duration::EIGHTH, double_duration(Duration::SIXTEENTH));
   EXPECT_EQ(Duration::QUARTER, double_duration(Duration::EIGHTH));
   EXPECT_EQ(Duration::HALF, double_duration(Duration::QUARTER));
   EXPECT_EQ(Duration::WHOLE, double_duration(Duration::HALF));
}



TEST(DurationTest, when_halving_SIXTYFOURTH_returns_SIXTYFOURTH)
{
   EXPECT_EQ(Duration::SIXTYFOURTH, half_duration(Duration::SIXTYFOURTH));
}



TEST(DurationTest, when_doubling_WHOLE_returns_WHOLE)
{
   EXPECT_EQ(Duration::WHOLE, double_duration(Duration::WHOLE));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



