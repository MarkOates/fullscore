


#include <gtest/gtest.h>

#include <fullscore/models/BeatCoordinate.hpp>
#include <fullscore/converters/stream_operators/BeatCoordinateStreamOperators.hpp>



TEST(BeatCoordinateTest, outputs_to_a_stream_operator)
{
   BeatCoordinate beat_coordinate(3, 7, 13);

   std::stringstream ss;

   ss << beat_coordinate;

   ASSERT_EQ("3 7 13", ss.str());
}



TEST(BeatCoordinateTest, inputs_from_a_stream_operator)
{
   BeatCoordinate beat_coordinate(0, 0, 0);

   std::stringstream ss;

   ss << "3 7 13";
   ss >> beat_coordinate;

   ASSERT_EQ(3, beat_coordinate.beat);
   ASSERT_EQ(7, beat_coordinate.sub_beat_numerator);
   ASSERT_EQ(13, beat_coordinate.sub_beat_denominator);
}



TEST(BeatCoordinateTest, stream_operators_are_symmetrical)
{
   BeatCoordinate beat_coordinate(3, 7, 13);

   std::string expected_string = "3 7 13";

   std::stringstream ss;

   ss << beat_coordinate;
   ss >> beat_coordinate;
   ss << beat_coordinate;

   ASSERT_EQ(expected_string, ss.str());
}



