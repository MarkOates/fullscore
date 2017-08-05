


#include <gtest/gtest.h>

#include <fullscore/models/staves/spacer.h>



TEST(Staff_SpacerTest, can_be_created)
{
   Staff::Spacer instrument(1);
}



TEST(Staff_SpacerTest, returns_a_staff_height_of_0_5)
{
   Staff::Spacer instrument(1);

   ASSERT_EQ(0.5, instrument.get_height());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



