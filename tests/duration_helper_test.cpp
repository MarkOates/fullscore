



#include <gtest/gtest.h>

#include <fullscore/helpers/duration_helper.h>
#include <fullscore/models/time_signature.h>




TEST(DurationHelperTest, returns_the_length_of_a_time_signature)
{
   TimeSignature time_signature_a(4, 4, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_a), 1.0);
}




int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}





