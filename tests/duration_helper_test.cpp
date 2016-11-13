



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
   EXPECT_EQ(DurationHelper::get_length(time_signature_c), 0.375);

   TimeSignature time_signature_n(5, 2, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_n), 2.5);

   TimeSignature time_signature_s(5, 16, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_s), 0.3125);

   TimeSignature time_signature_d(2, 4, 1);
   TimeSignature time_signature_e(6, 8, 0);
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), 0.75);
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), DurationHelper::get_length(time_signature_e));
   EXPECT_EQ(DurationHelper::get_length(time_signature_d), DurationHelper::get_length(time_signature_b));
}




int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}





