



#include <gtest/gtest.h>

#include <fullscore/helpers/duration_helper.h>
#include <fullscore/models/time_signature.h>




TEST(DurationHelperTest, returns_the_length_of_a_time_signature)
{
   TimeSignature time_signature_a(4, 4, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_a), 1.0);

   TimeSignature time_signature_b(3, 4, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_b), 0.75);

   TimeSignature time_signature_c(3, 8, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_c), 0.75);

   TimeSignature time_signature_d(2, 4, 1);
   TimeSignature time_signature_e(6, 8, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), 0.375);
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), DurationHelper::get_length(time_signature_e));
}




int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}





