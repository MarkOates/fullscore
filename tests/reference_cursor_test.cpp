


#include <gtest/gtest.h>



#include <fullscore/models/reference_cursor.h>

#include <fullscore/models/grid.h>



TEST(ReferenceCursorTest, can_be_constructed_with_an_empty_constructor)
{
   ReferenceCursor reference_cursor;

   EXPECT_EQ(nullptr, reference_cursor.get_grid());
   EXPECT_EQ(0, reference_cursor.get_x());
   EXPECT_EQ(0, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, can_be_constructed_with_arguments)
{
   MeasureGrid grid(1, 1);
   ReferenceCursor reference_cursor(&grid, 9, 16);

   EXPECT_EQ(&grid, reference_cursor.get_grid());
   EXPECT_EQ(9, reference_cursor.get_x());
   EXPECT_EQ(16, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, can_set_its_position)
{
   MeasureGrid grid_1(1, 1);
   MeasureGrid grid_2(1, 1);
   ReferenceCursor reference_cursor;

   reference_cursor.set_position(&grid_1, 9, 16);

   EXPECT_EQ(&grid_1, reference_cursor.get_grid());
   EXPECT_EQ(9, reference_cursor.get_x());
   EXPECT_EQ(16, reference_cursor.get_y());

   reference_cursor.set_position(&grid_2, 19, 7);

   EXPECT_EQ(&grid_2, reference_cursor.get_grid());
   EXPECT_EQ(19, reference_cursor.get_x());
   EXPECT_EQ(7, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, can_set_its_x_y_coordinates)
{
   ReferenceCursor reference_cursor;

   reference_cursor.set_coordinates(20, 30);

   EXPECT_EQ(20, reference_cursor.get_x());
   EXPECT_EQ(30, reference_cursor.get_y());

   reference_cursor.set_coordinates(17, 26);

   EXPECT_EQ(17, reference_cursor.get_x());
   EXPECT_EQ(26, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, can_move_its_x_y_coordinates)
{
   ReferenceCursor reference_cursor;

   reference_cursor.move(20, 30);

   EXPECT_EQ(20, reference_cursor.get_x());
   EXPECT_EQ(30, reference_cursor.get_y());

   reference_cursor.move(17, 26);

   EXPECT_EQ(37, reference_cursor.get_x());
   EXPECT_EQ(56, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, with_no_grid__is_invalid)
{
   ReferenceCursor reference_cursor;

   EXPECT_FALSE(reference_cursor.is_valid());
}



TEST(ReferenceCursorTest, with_a_reference_grid_and_coordinates_within_the_grid__is_valid)
{
   MeasureGrid grid(3, 4);
   ReferenceCursor reference_cursor(&grid, 2, 1);

   EXPECT_TRUE(reference_cursor.is_valid());
}



TEST(ReferenceCursorTest, with_a_reference_grid_and_coordinates_outside_the_grid__is_invalid)
{
   MeasureGrid grid(3, 4);
   ReferenceCursor reference_cursor(&grid, 2, 1);

   reference_cursor.set_coordinates(999, 999);

   EXPECT_FALSE(reference_cursor.is_valid());

   reference_cursor.set_coordinates(-1, 1);

   EXPECT_FALSE(reference_cursor.is_valid());

   reference_cursor.set_coordinates(1, -1);

   EXPECT_FALSE(reference_cursor.is_valid());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}




