


#include <gtest/gtest.h>

#include <fullscore/models/floating_measure.h>

#include <fullscore/models/measures/basic.h>



TEST(FloatingMeasureTest, can_be_created)
{
   FloatingMeasure floating_measure(GridCoordinate(), 0);
}



TEST(FloatingMeasureTest, returns_its_measure_id)
{
   FloatingMeasure floating_measure(GridCoordinate(), 1234);

   ASSERT_EQ(1234, floating_measure.get_measure_id());
}



TEST(FloatingMeasureTest, returns_its_coordinate)
{
   GridCoordinate coordinate(nullptr, 7, 11, 3);
   FloatingMeasure floating_measure(coordinate, 0);

   ASSERT_EQ(coordinate, floating_measure.get_coordinate());
}



TEST(FloatingMeasureTest, is_assigned_an_incremented_id_when_created)
{
   int next_id = FloatingMeasure::get_next_id();

   FloatingMeasure floating_measure_1(GridCoordinate(), 0);
   FloatingMeasure floating_measure_2(GridCoordinate(), 0);
   FloatingMeasure floating_measure_3(GridCoordinate(), 0);

   ASSERT_EQ(next_id + 0, floating_measure_1.get_id());
   ASSERT_EQ(next_id + 1, floating_measure_2.get_id());
   ASSERT_EQ(next_id + 2, floating_measure_3.get_id());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



