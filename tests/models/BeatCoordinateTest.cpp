


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



TEST(BeatCoordinateTest, returns_the_correct_x_offset)
{
   BeatCoordinate beat_coordinate(3, 7, 8);

   ASSERT_EQ(3.875, beat_coordinate.get_x_offset());
}



TEST(BeatCoordinateTest, with_a_sub_beat_denominator_of_zero_does_not_divide_by_zero)
{
   BeatCoordinate beat_coordinate(3, 7, 0);

   ASSERT_EQ(3.0, beat_coordinate.get_x_offset());
}



TEST(BeatCoordinateTest, returns_true_when_two_beat_coordinates_are_equal)
{
   ASSERT_EQ(true, BeatCoordinate(3, 7, 8) == BeatCoordinate(3, 7, 8));

   ASSERT_EQ(false, BeatCoordinate(999, 7, 8) == BeatCoordinate(3, 7, 8));
   ASSERT_EQ(false, BeatCoordinate(3, 999, 8) == BeatCoordinate(3, 7, 8));
   ASSERT_EQ(false, BeatCoordinate(3, 7, 999) == BeatCoordinate(3, 7, 8));
}



TEST(BeatCoordinateTest, returns_false_when_two_beat_coordinates_are_not_equal)
{
   ASSERT_EQ(true, BeatCoordinate(999, 7, 8) != BeatCoordinate(3, 7, 8));
   ASSERT_EQ(true, BeatCoordinate(3, 999, 8) != BeatCoordinate(3, 7, 8));
   ASSERT_EQ(true, BeatCoordinate(3, 7, 999) != BeatCoordinate(3, 7, 8));

   ASSERT_EQ(false, BeatCoordinate(3, 7, 8) != BeatCoordinate(3, 7, 8));
}



