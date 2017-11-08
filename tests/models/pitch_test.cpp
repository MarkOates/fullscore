


#include <gtest/gtest.h>

#include <fullscore/models/pitch.h>



TEST(PitchTest, can_be_created)
{
   Pitch pitch(0, 0);
}



TEST(PitchTest, equality_operator_returns_true_on_equal_pitch)
{
   EXPECT_EQ(true, Pitch(0, 0).operator==(Pitch(0, 0)));
   EXPECT_EQ(true, Pitch(-2, 1).operator==(Pitch(-2, 1)));
   EXPECT_EQ(true, Pitch(4, -1).operator==(Pitch(4, -1)));
}



TEST(PitchTest, equality_operator_returns_false_on_unequal_pitch)
{
   EXPECT_EQ(false, Pitch(0, 0).operator==(Pitch(1, 0)));
   EXPECT_EQ(false, Pitch(-3, 0).operator==(Pitch(-3, 1)));
   EXPECT_EQ(false, Pitch(14, 1).operator==(Pitch(-3, 2)));
}



