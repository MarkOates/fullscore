


#include <gtest/gtest.h>

#include <fullscore/models/TimeSignature.hpp>
#include <fullscore/converters/stream_operators/TimeSignatureStreamOperators.h>



TEST(TimeSignatureStreamOperatorsTest, outputs_to_a_stream_operator)
{
   TimeSignature time_signature(7, Duration(Duration::HALF, 3));

   std::stringstream ss;

   ss << time_signature;

   ASSERT_EQ("7 2 3", ss.str());
}



TEST(TimeSignatureStreamOperatorsTest, inputs_from_a_stream_operator)
{
   TimeSignature time_signature(4, Duration(Duration::QUARTER));

   std::stringstream ss;

   ss << "7 2 3";
   ss >> time_signature;

   ASSERT_EQ(7, time_signature.get_numerator());
   ASSERT_EQ(Duration(Duration::HALF, 3), time_signature.get_denominator());
}



TEST(TimeSignatureStreamOperatorsTest, stream_operators_are_symmetrical)
{
   TimeSignature time_signature(7, Duration(Duration::QUARTER, 3));

   std::string expected_string = "7 4 3";

   std::stringstream ss;

   ss << time_signature;
   ss >> time_signature;
   ss << time_signature;

   ASSERT_EQ(expected_string, ss.str());
}



