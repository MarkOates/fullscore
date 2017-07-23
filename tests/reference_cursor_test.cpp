


#include <gtest/gtest.h>



#include <fullscore/reference_cursor.h>

#include <fullscore/models/measure_grid.h>



TEST(ReferenceCursorTest, can_be_constructed_with_an_empty_constructor)
{
   ReferenceCursor reference_cursor;

   EXPECT_EQ(nullptr, reference_cursor.get_measure_grid());
   EXPECT_EQ(0, reference_cursor.get_x());
   EXPECT_EQ(0, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, can_be_constructed_with_arguments)
{
   MeasureGrid measure_grid(1, 1);
   ReferenceCursor reference_cursor(&measure_grid, 9, 16);

   EXPECT_EQ(&measure_grid, reference_cursor.get_measure_grid());
   EXPECT_EQ(9, reference_cursor.get_x());
   EXPECT_EQ(16, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, can_set_its_position)
{
   MeasureGrid measure_grid_1(1, 1);
   MeasureGrid measure_grid_2(1, 1);
   ReferenceCursor reference_cursor;

   reference_cursor.set_position(&measure_grid_1, 9, 16);

   EXPECT_EQ(&measure_grid_1, reference_cursor.get_measure_grid());
   EXPECT_EQ(9, reference_cursor.get_x());
   EXPECT_EQ(16, reference_cursor.get_y());

   reference_cursor.set_position(&measure_grid_2, 19, 7);

   EXPECT_EQ(&measure_grid_2, reference_cursor.get_measure_grid());
   EXPECT_EQ(19, reference_cursor.get_x());
   EXPECT_EQ(7, reference_cursor.get_y());
}



TEST(ReferenceCursorTest, can_set_its_x_y_coordinates)
{
   ReferenceCursor reference_cursor;

   reference_cursor.set(20, 30);

   EXPECT_EQ(20, reference_cursor.get_x());
   EXPECT_EQ(30, reference_cursor.get_y());

   reference_cursor.set(17, 26);

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



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}




