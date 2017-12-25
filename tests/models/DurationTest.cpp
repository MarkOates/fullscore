


#include <gtest/gtest.h>

#include <fullscore/models/Duration.h>



TEST(DurationTest, can_be_created)
{
   Duration duration(Duration::HALF, 0);
}



TEST(DurationTest, can_get_the_dots)
{
   Duration duration(Duration::QUARTER, 0);
   EXPECT_EQ(0, duration.get_dots());

   Duration duration(Duration::QUARTER, 3);
   EXPECT_EQ(3, duration.get_dots());

   Duration duration(Duration::QUARTER, 99);
   EXPECT_EQ(99, duration.get_dots());
}



TEST(DurationTest, can_set_the_dots)
{
   Duration duration();

   duration.set_dots(0);
   EXPECT_EQ(0, duration.get_dots());

   duration.set_dots(3);
   EXPECT_EQ(3, duration.get_dots());

   duration.set_dots(99);
   EXPECT_EQ(99, duration.get_dots());
}



TEST(DurationTest, can_get_the_denominator)
{
   Duration duration(Duration::HALF, 0);
   EXPECT_EQ(Duration::HALF, duration.get_denominator());

   Duration duration(Duration::QUARTER, 0);
   EXPECT_EQ(Duration::QUARTER, duration.get_denominator());

   Duration duration(Duration::SIXTYFOURTH, 0);
   EXPECT_EQ(Duration::SIXTYFOURTH, duration.get_denominator());
}



TEST(DurationTest, can_set_the_denominator)
{
   Duration duration(Duration::HALF, 0);

   duration.set_denominator(Duration::QUARTER);
   EXPECT_EQ(Duration::QUARTER, duration.get_denominator());

   duration.set_denominator(Duration::EIGHTH);
   EXPECT_EQ(Duration::EIGHTH, duration.get_denominator());

   duration.set_denominator(Duration::SIXTYFOURTH);
   EXPECT_EQ(Duration::SIXTYFOURTH, duration.get_denominator());
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



TEST(DurationTest, returns_true_if_an_integer_is_a_valid_denominator)
{
   EXPECT_EQ(true, Duration::is_valid_denominator(Duration::WHOLE));
   EXPECT_EQ(true, Duration::is_valid_denominator(Duration::EIGHTH));
   EXPECT_EQ(true, Duration::is_valid_denominator(Duration::SIXTYFOURTH));
}



TEST(DurationTest, returns_false_if_an_integer_is_an_invalid_denominator)
{
   EXPECT_EQ(false, Duration::is_valid_denominator(-1));
   EXPECT_EQ(false, Duration::is_valid_denominator(0));
   EXPECT_EQ(false, Duration::is_valid_denominator(3));
   EXPECT_EQ(false, Duration::is_valid_denominator(7));
   EXPECT_EQ(false, Duration::is_valid_denominator(999));
}



