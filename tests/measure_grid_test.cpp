


#include <gtest/gtest.h>

#include <fullscore/models/measure_grid.h>
#include <fullscore/models/note.h>



TEST(MeasureGridTest, creates_successfully)
{
   MeasureGrid measure_grid(1, 1);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



