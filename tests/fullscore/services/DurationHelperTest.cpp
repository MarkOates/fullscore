



#include <gtest/gtest.h>

#include <fullscore/services/DurationHelper.hpp>
#include <fullscore/models/TimeSignature.hpp>




TEST(DurationHelperTest, returns_the_length_of_a_duration)
{
   Duration duration_a(Duration::QUARTER, 0);
   EXPECT_EQ(0.25, DurationHelper::get_length(duration_a));

   Duration duration_b(Duration::WHOLE, 0);
   EXPECT_EQ(1.0, DurationHelper::get_length(duration_b));

   Duration duration_c(Duration::HALF, 2);
   EXPECT_EQ(0.875, DurationHelper::get_length(duration_c));

   Duration duration_d(Duration::QUARTER, 1);
   EXPECT_EQ(0.375, DurationHelper::get_length(duration_d));

   Duration duration_e(Duration::SIXTEENTH, 0);
   EXPECT_EQ(0.0625, DurationHelper::get_length(duration_e));
}




TEST(DurationHelperTest, returns_the_length_of_a_time_signature)
{
   TimeSignature time_signature_a(4, Duration(Duration::QUARTER, 0));
   EXPECT_EQ(DurationHelper::get_length(time_signature_a), 1.0);

   TimeSignature time_signature_b(3, Duration(Duration::QUARTER, 0));
   EXPECT_EQ(DurationHelper::get_length(time_signature_b), 0.75);

   TimeSignature time_signature_c(3, Duration(Duration::EIGHTH, 0));
   EXPECT_EQ(DurationHelper::get_length(time_signature_c), 0.375);

   TimeSignature time_signature_n(5, Duration(Duration::HALF, 0));
   EXPECT_EQ(DurationHelper::get_length(time_signature_n), 2.5);

   TimeSignature time_signature_s(5, Duration(Duration::SIXTEENTH, 0));
   EXPECT_EQ(DurationHelper::get_length(time_signature_s), 0.3125);

   TimeSignature time_signature_d(2, Duration(Duration::QUARTER, 1));
   TimeSignature time_signature_e(6, Duration(Duration::EIGHTH, 0));
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), 0.75);
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), DurationHelper::get_length(time_signature_e));
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), DurationHelper::get_length(time_signature_b));
}




TEST(DurationTest, half_duration__halves_the_duration)
{
   EXPECT_EQ(Duration::SIXTYFOURTH, DurationHelper::half_duration(Duration::THIRTYSECOND));
   EXPECT_EQ(Duration::THIRTYSECOND, DurationHelper::half_duration(Duration::SIXTEENTH));
   EXPECT_EQ(Duration::SIXTEENTH, DurationHelper::half_duration(Duration::EIGHTH));
   EXPECT_EQ(Duration::QUARTER, DurationHelper::half_duration(Duration::HALF));
   EXPECT_EQ(Duration::HALF, DurationHelper::half_duration(Duration::WHOLE));
}



TEST(DurationTest, double_duration__doubles_the_duration)
{
   EXPECT_EQ(Duration::THIRTYSECOND, DurationHelper::double_duration(Duration::SIXTYFOURTH));
   EXPECT_EQ(Duration::SIXTEENTH, DurationHelper::double_duration(Duration::THIRTYSECOND));
   EXPECT_EQ(Duration::EIGHTH, DurationHelper::double_duration(Duration::SIXTEENTH));
   EXPECT_EQ(Duration::QUARTER, DurationHelper::double_duration(Duration::EIGHTH));
   EXPECT_EQ(Duration::HALF, DurationHelper::double_duration(Duration::QUARTER));
   EXPECT_EQ(Duration::WHOLE, DurationHelper::double_duration(Duration::HALF));
}



TEST(DurationTest, half_duration__when_halving_SIXTYFOURTH_returns_SIXTYFOURTH)
{
   EXPECT_EQ(Duration::SIXTYFOURTH, DurationHelper::half_duration(Duration::SIXTYFOURTH));
}



TEST(DurationTest, double_duration__when_doubling_WHOLE_returns_WHOLE)
{
   EXPECT_EQ(Duration::WHOLE, DurationHelper::double_duration(Duration::WHOLE));
}



