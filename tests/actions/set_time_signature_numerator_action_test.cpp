


#include <gtest/gtest.h>

#include <fullscore/actions/set_time_signature_numerator_action.h>
#include <fullscore/models/time_signature.h>



TEST(SetTimeSignatureNumeratorActionTest, sets_the_time_signatures_numerator)
{
   TimeSignature time_signature(4, Duration());

   EXPECT_EQ(4, time_signature.get_numerator());

   Action::SetTimeSignatureNumerator set_time_signature_numerator_action(&time_signature, 3);
   set_time_signature_numerator_action.execute();

   EXPECT_EQ(3, time_signature.get_numerator());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



