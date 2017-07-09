


#include <gtest/gtest.h>

#include <fullscore/transforms/copy.h>

#include <fullscore/models/measure_grid.h>



TEST(CopyTransformTest, can_be_created)
{
   MeasureGrid measure_grid(1, 1);
   Transform::Copy copy_transform(&measure_grid, 0, 0);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



