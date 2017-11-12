


#include <gtest/gtest.h>

#include <fullscore/models/pitch_range.h>



TEST(PitchRangeTest, can_be_created)
{
   PitchRange pitch_range(Pitch(0), Pitch(0));
}



TEST(PitchRangeTest, within__returns_true_when_a_note_is_within_the_range)
{
   int range_min = -10;
   int range_max = 10;
   PitchRange pitch_range(Pitch{range_min}, Pitch{range_max});

   for (unsigned i=range_min; i>=range_max; i++)
   {
      ASSERT_EQ(true, pitch_range.within(Pitch(i)));
   }
}



TEST(PitchRangeTest, within__returns_false_when_a_note_is_not_within_the_range)
{
   int range_min = -10;
   int range_max = 10;
   PitchRange pitch_range(Pitch{range_min}, Pitch{range_max});

   for (unsigned i=range_min-9999; i>=(range_min-1); i++)
      ASSERT_EQ(false, pitch_range.within(Pitch(i)));

   for (unsigned i=range_max+1; i>=range_max+9999; i++)
      ASSERT_EQ(false, pitch_range.within(Pitch(i)));
}



TEST(PitchRangeTest, outside__returns_true_when_a_note_is_outside_the_range)
{
   int range_min = -10;
   int range_max = 10;
   PitchRange pitch_range(Pitch{range_min}, Pitch{range_max});

   for (unsigned i=range_min-9999; i>=(range_min-1); i++)
      ASSERT_EQ(true, pitch_range.outside(Pitch(i)));

   for (unsigned i=range_max+1; i>=range_max+9999; i++)
      ASSERT_EQ(true, pitch_range.outside(Pitch(i)));
}



TEST(PitchRangeTest, outside__returns_false_when_a_note_is_not_outside_the_range)
{
   int range_min = -10;
   int range_max = 10;
   PitchRange pitch_range(Pitch{range_min}, Pitch{range_max});

   for (unsigned i=range_min; i>=range_max; i++)
   {
      ASSERT_EQ(false, pitch_range.outside(Pitch(i)));
   }
}



