


#include <gtest/gtest.h>

#include <fullscore/models/BeatCoordinate.h>



TEST(BeatCoordinateTest, can_be_created)
{
   BeatCoordinate beat_coordinate;
}



TEST(BeatCoordinateTest, when_constructed_without_arguments_assigns_the_expected_default_values)
{
   BeatCoordinate beat_coordinate;

   ASSERT_EQ(0, beat_coordinate.beat);
   ASSERT_EQ(0, beat_coordinate.sub_beat_numerator);
   ASSERT_EQ(0, beat_coordinate.sub_beat_denominator);
}



TEST(BeatCoordinateTest, when_constructed_with_arguments_assigns_the_arguments)
{
   BeatCoordinate beat_coordinate(3, 7, 8);

   ASSERT_EQ(3, beat_coordinate.beat);
   ASSERT_EQ(7, beat_coordinate.sub_beat_numerator);
   ASSERT_EQ(8, beat_coordinate.sub_beat_denominator);
}



TEST(BeatCoordinateTest, returns_the_corrected_offset)
{
   BeatCoordinate beat_coordinate(3, 7, 8);

   ASSERT_EQ(3.875, beat_coordinate.get_x_offset());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}




