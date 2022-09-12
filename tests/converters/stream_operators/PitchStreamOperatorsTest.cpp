


#include <gtest/gtest.h>

#include <fullscore/converters/stream_operators/PitchStreamOperators.h>
#include <fullscore/models/Pitch.hpp>



TEST(PitchStreamOperatorsTest, outputs_to_a_stream_operator)
{
   Pitch pitch(4, 7);

   std::stringstream ss;

   ss << pitch;

   ASSERT_EQ("4 7", ss.str());
}



TEST(PitchStreamOperatorsTest, inputs_from_a_stream_operator)
{
   Pitch pitch(0);

   std::stringstream ss;

   ss << "2 7";
   ss >> pitch;

   ASSERT_EQ(2, pitch.get_scale_degree());
   ASSERT_EQ(7, pitch.get_accidental());
}



TEST(PitchStreamOperatorsTest, stream_operators_are_symmetrical)
{
   Pitch pitch(4, 7);

   std::string expected_string = "4 7";

   std::stringstream ss;

   ss << pitch;
   ss >> pitch;
   ss << pitch;

   ASSERT_EQ(expected_string, ss.str());
}



