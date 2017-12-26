


#include <gtest/gtest.h>

#include <fullscore/models/Pitch.h>



TEST(PitchTest, can_be_created)
{
   Pitch pitch(0, 0);
}



TEST(PitchTest, when_initialized_without_arguments_scale_degree_is_set_to_0)
{
   Pitch pitch;
   EXPECT_EQ(0, pitch.get_scale_degree());
}



TEST(PitchTest, when_initialized_without_arguments_accidental_is_set_to_0)
{
   Pitch pitch;
   EXPECT_EQ(0, pitch.get_accidental());
}



TEST(PitchTest, can_get_and_set_scale_degree)
{
   Pitch pitch;

   EXPECT_EQ(true, pitch.set_scale_degree(-4));
   EXPECT_EQ(-4, pitch.get_scale_degree());

   EXPECT_EQ(true, pitch.set_scale_degree(9));
   EXPECT_EQ(9, pitch.get_scale_degree());

   EXPECT_EQ(true, pitch.set_scale_degree(999));
   EXPECT_EQ(999, pitch.get_scale_degree());

   EXPECT_EQ(true, pitch.set_scale_degree(0));
   EXPECT_EQ(0, pitch.get_scale_degree());
}



TEST(PitchTest, can_get_and_set_accidental)
{
   Pitch pitch;

   EXPECT_EQ(true, pitch.set_accidental(-4));
   EXPECT_EQ(-4, pitch.get_accidental());

   EXPECT_EQ(true, pitch.set_accidental(9));
   EXPECT_EQ(9, pitch.get_accidental());

   EXPECT_EQ(true, pitch.set_accidental(999));
   EXPECT_EQ(999, pitch.get_accidental());

   EXPECT_EQ(true, pitch.set_accidental(0));
   EXPECT_EQ(0, pitch.get_accidental());
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



TEST(PitchTest, gt_operator_returns_true_when_a_passed_pitch_is_gt_pitch)
{
   EXPECT_EQ(true, Pitch(1, 0).operator>(Pitch(0, 0)));
   EXPECT_EQ(true, Pitch(0, 0).operator>(Pitch(-3, 1)));
   EXPECT_EQ(true, Pitch(0, 1).operator>(Pitch(0, 0)));
   EXPECT_EQ(true, Pitch(999, 999).operator>(Pitch(0, 0)));
}



TEST(PitchTest, gt_operator_returns_false_when_a_passed_pitch_is_gt_pitch)
{
   EXPECT_EQ(false, Pitch(0, 0).operator>(Pitch(0, 0)));
   EXPECT_EQ(false, Pitch(0, 0).operator>(Pitch(1, 0)));
   EXPECT_EQ(false, Pitch(-3, 1).operator>(Pitch(0, 0)));
   EXPECT_EQ(false, Pitch(0, 0).operator>(Pitch(0, 1)));
   EXPECT_EQ(false, Pitch(0, 0).operator>(Pitch(999, 999)));
}



TEST(PitchTest, lt_operator_returns_true_when_a_passed_pitch_is_lt_pitch)
{
   EXPECT_EQ(true, Pitch(0, 0).operator<(Pitch(1, 0)));
   EXPECT_EQ(true, Pitch(-3, 1).operator<(Pitch(0, 0)));
   EXPECT_EQ(true, Pitch(0, 0).operator<(Pitch(0, 1)));
   EXPECT_EQ(true, Pitch(0, 0).operator<(Pitch(999, 999)));
}



TEST(PitchTest, lt_operator_returns_false_when_a_passed_pitch_is_lt_pitch)
{
   EXPECT_EQ(false, Pitch(0, 0).operator<(Pitch(0, 0)));
   EXPECT_EQ(false, Pitch(1, 0).operator<(Pitch(0, 0)));
   EXPECT_EQ(false, Pitch(0, 0).operator<(Pitch(-3, 1)));
   EXPECT_EQ(false, Pitch(0, 1).operator<(Pitch(0, 0)));
   EXPECT_EQ(false, Pitch(999, 999).operator<(Pitch(0, 0)));
}



