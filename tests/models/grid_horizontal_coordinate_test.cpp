


#include <gtest/gtest.h>

#include <fullscore/models/grid_horizontal_coordinate.h>



TEST(GridHorizontalCoordinate, can_be_created)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;
}



TEST(GridHorizontalCoordinate, gets_and_sets_the_barline_num)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;

   grid_horizontal_coordinate.set_barline_num(123);
   EXPECT_EQ(123, grid_horizontal_coordinate.get_barline_num());

   grid_horizontal_coordinate.set_barline_num(-86);
   EXPECT_EQ(-86, grid_horizontal_coordinate.get_barline_num());

   grid_horizontal_coordinate.set_barline_num(720782);
   EXPECT_EQ(720782, grid_horizontal_coordinate.get_barline_num());
}



TEST(GridHorizontalCoordinate, gets_and_sets_the_beat_coordinate)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;

   grid_horizontal_coordinate.set_beat_coordinate(BeatCoordinate(123));
   EXPECT_EQ(BeatCoordinate(123), grid_horizontal_coordinate.get_beat_coordinate());

   grid_horizontal_coordinate.set_beat_coordinate(BeatCoordinate(-86));
   EXPECT_EQ(BeatCoordinate(-86), grid_horizontal_coordinate.get_beat_coordinate());

   grid_horizontal_coordinate.set_beat_coordinate(BeatCoordinate(720782));
   EXPECT_EQ(BeatCoordinate(720782), grid_horizontal_coordinate.get_beat_coordinate());
}



TEST(GridHorizontalCoordinate, on_construction_without_arguments_hasthe_expected_default_values)
{
   GridHorizontalCoordinate grid_horizontal_coordinate;

   EXPECT_EQ(0, grid_horizontal_coordinate.get_barline_num());
   EXPECT_EQ(BeatCoordinate(), grid_horizontal_coordinate.get_beat_coordinate());
}



TEST(GridHorizontalCoordinate, on_construction_with_arguments_initializes_the_expected_values)
{
   GridHorizontalCoordinate grid_horizontal_coordinate(98, BeatCoordinate(123));

   EXPECT_EQ(98, grid_horizontal_coordinate.get_barline_num());
   EXPECT_EQ(BeatCoordinate(123), grid_horizontal_coordinate.get_beat_coordinate());
}



TEST(GridHorizontalCoordinate, returns_true_when_two_coordinates_are_equal)
{
   GridHorizontalCoordinate grid_horizontal_coordinate(98, BeatCoordinate(123));

   ASSERT_EQ(true, GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)) == GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));

   ASSERT_EQ(false, GridHorizontalCoordinate(42, BeatCoordinate(999, 7, 8)) == GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));
   ASSERT_EQ(false, GridHorizontalCoordinate(42, BeatCoordinate(3, 999, 8)) == GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));
   ASSERT_EQ(false, GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 999)) == GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));
   ASSERT_EQ(false, GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)) == GridHorizontalCoordinate(999, BeatCoordinate(3, 7, 8)));
}



TEST(GridHorizontalCoordinate, returns_false_when_two_coordinates_are_not_equal)
{
   GridHorizontalCoordinate grid_horizontal_coordinate(98, BeatCoordinate(123));

   ASSERT_EQ(false, GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)) != GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));

   ASSERT_EQ(true, GridHorizontalCoordinate(42, BeatCoordinate(999, 7, 8)) != GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));
   ASSERT_EQ(true, GridHorizontalCoordinate(42, BeatCoordinate(3, 999, 8)) != GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));
   ASSERT_EQ(true, GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 999)) != GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)));
   ASSERT_EQ(true, GridHorizontalCoordinate(42, BeatCoordinate(3, 7, 8)) != GridHorizontalCoordinate(999, BeatCoordinate(3, 7, 8)));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



