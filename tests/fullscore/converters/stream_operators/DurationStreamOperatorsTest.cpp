


#include <gtest/gtest.h>

#include <fullscore/models/Duration.hpp>
#include <fullscore/converters/stream_operators/DurationStreamOperators.h>



TEST(DurationStreamOperatorsTest, outputs_to_a_stream_operator)
{
   Duration duration(Duration::QUARTER, 7);

   std::stringstream ss;

   ss << duration;

   ASSERT_EQ("4 7", ss.str());
}



TEST(DurationStreamOperatorsTest, inputs_from_a_stream_operator)
{
   Duration duration(Duration::QUARTER, 0);

   std::stringstream ss;

   ss << "2 7";
   ss >> duration;

   ASSERT_EQ(Duration::HALF, duration.get_denominator());
   ASSERT_EQ(7, duration.get_dots());
}



TEST(DurationStreamOperatorsTest, stream_operators_are_symmetrical)
{
   Duration duration(Duration::QUARTER, 7);

   std::string expected_string = "4 7";

   std::stringstream ss;

   ss << duration;
   ss >> duration;
   ss << duration;

   ASSERT_EQ(expected_string, ss.str());
}



