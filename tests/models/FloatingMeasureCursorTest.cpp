


#include <gtest/gtest.h>

#include <fullscore/models/FloatingMeasureCursor.h>



TEST(FloatingMeasureCursorTest, can_be_created)
{
   FloatingMeasureCursor floating_measure_cursor;
}



TEST(FloatingMeasureCursorTest, initializes_with_a_measure_id_of_negative_1)
{
   FloatingMeasureCursor floating_measure_cursor;

   EXPECT_EQ(-1, floating_measure_cursor.get_floating_measure_id());
}



TEST(FloatingMeasureCursorTest, clearing_the_floating_measure_id_sets_floating_measure_id_to_negative_1)
{
   FloatingMeasureCursor floating_measure_cursor;

   EXPECT_EQ(true, floating_measure_cursor.set_floating_measure_id(123));
   EXPECT_EQ(123, floating_measure_cursor.get_floating_measure_id());
   floating_measure_cursor.clear_floating_measure_id();
   EXPECT_EQ(-1, floating_measure_cursor.get_floating_measure_id());
}



TEST(FloatingMeasureCursorTest, can_set_and_get_a_floating_measure_id)
{
   FloatingMeasureCursor floating_measure_cursor;

   EXPECT_EQ(-1, floating_measure_cursor.get_floating_measure_id());
   EXPECT_EQ(true, floating_measure_cursor.set_floating_measure_id(123));
   EXPECT_EQ(123, floating_measure_cursor.get_floating_measure_id());
   EXPECT_EQ(true, floating_measure_cursor.set_floating_measure_id(6));
   EXPECT_EQ(6, floating_measure_cursor.get_floating_measure_id());
}



