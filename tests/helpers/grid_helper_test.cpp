



#include <gtest/gtest.h>

#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/staves/spacer.h>
#include <fullscore/helpers/grid_helper.h>
#include <fullscore/models/grid.h>
#include <fullscore/models/Note.h>




TEST(GridHelperTest, returns_the_length_to_the_measure_of_4_4_measures)
{
   Grid grid(10, 1);
   EXPECT_EQ(GridHelper::get_length_to_measure(grid, 0), 0.0);
   EXPECT_EQ(GridHelper::get_length_to_measure(grid, 1), 1.0);
   EXPECT_EQ(GridHelper::get_length_to_measure(grid, 2), 2.0);
   EXPECT_EQ(GridHelper::get_length_to_measure(grid, 9), 9.0);
}




TEST(GridHelperTest, returns_the_length_to_the_end_of_the_grid_when_measure_index_is_gt_total_measures)
{
   Grid grid(10, 1);
   EXPECT_EQ(GridHelper::get_length_to_measure(grid, 10), 10.0);
   EXPECT_EQ(GridHelper::get_length_to_measure(grid, 11), 10.0);
   EXPECT_EQ(GridHelper::get_length_to_measure(grid, 9999), 10.0);
}




TEST(GridHelperTest, returns_the_length_to_the_measure_with_non_4_4_time_signatures)
{
   Grid grid(10, 1);

   grid.set_time_signature(0, TimeSignature(3, Duration(Duration::QUARTER, 0)));
   grid.set_time_signature(1, TimeSignature(5, Duration(Duration::QUARTER, 0)));
   grid.set_time_signature(2, TimeSignature(6, Duration(Duration::EIGHTH, 0)));
   grid.set_time_signature(3, TimeSignature(5, Duration(Duration::SIXTEENTH, 0)));
   grid.set_time_signature(4, TimeSignature(5, Duration(Duration::HALF, 0)));
   grid.set_time_signature(5, TimeSignature(9, Duration(Duration::EIGHTH, 0)));

   ASSERT_EQ(GridHelper::get_length_to_measure(grid, 1), 0.75);
   ASSERT_EQ(GridHelper::get_length_to_measure(grid, 2), 2.0);
   ASSERT_EQ(GridHelper::get_length_to_measure(grid, 3), 2.75);
   ASSERT_EQ(GridHelper::get_length_to_measure(grid, 4), 3.0625); // + 0.3125
   ASSERT_EQ(GridHelper::get_length_to_measure(grid, 5), 5.5625); // + 2.5
   ASSERT_EQ(GridHelper::get_length_to_measure(grid, 6), 6.6875); // + 1.125
}




TEST(GridHelperTest, can_get_the_width_of_a_grid)
{
   Grid grid(0, 1);

   grid.append_measure();
   grid.append_measure();
   grid.append_measure();
   grid.append_measure();
   grid.append_measure();

   grid.set_time_signature(3, TimeSignature(3, Duration(Duration::EIGHTH)));

   ASSERT_EQ(4.375, GridHelper::get_width(grid));
}




TEST(GridHelperTest, can_get_its_height_up_to_a_staff)
{
   Grid grid(1, 0);

   Staff::Instrument instrument1(1);
   Staff::Spacer spacer1(1);
   Staff::Instrument instrument2(1);
   Staff::Spacer spacer2(1);
   Staff::Spacer spacer3(1);

   grid.append_staff(&instrument1);
   grid.append_staff(&spacer1);
   grid.append_staff(&instrument2);
   grid.append_staff(&spacer2);
   grid.append_staff(&spacer3);

   ASSERT_EQ(0.0, GridHelper::get_height_to_staff(grid, 0));
   ASSERT_EQ(1.0, GridHelper::get_height_to_staff(grid, 1));
   ASSERT_EQ(1.5, GridHelper::get_height_to_staff(grid, 2));
   ASSERT_EQ(2.5, GridHelper::get_height_to_staff(grid, 3));
   ASSERT_EQ(3.0, GridHelper::get_height_to_staff(grid, 4));
}




TEST(GridHelperTest, can_get_height_of_a_staff)
{
   Grid grid(1, 0);

   Staff::Instrument instrument1(1);
   Staff::Spacer spacer1(1);
   Staff::Instrument instrument2(1);
   Staff::Spacer spacer2(1);
   Staff::Spacer spacer3(1);

   grid.append_staff(&instrument1);
   grid.append_staff(&spacer1);
   grid.append_staff(&instrument2);
   grid.append_staff(&spacer2);
   grid.append_staff(&spacer3);

   ASSERT_EQ(1.0, GridHelper::get_height_of_staff(grid, 0));
   ASSERT_EQ(0.5, GridHelper::get_height_of_staff(grid, 1));
   ASSERT_EQ(1.0, GridHelper::get_height_of_staff(grid, 2));
   ASSERT_EQ(0.5, GridHelper::get_height_of_staff(grid, 3));
   ASSERT_EQ(0.5, GridHelper::get_height_of_staff(grid, 4));
}




int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}





