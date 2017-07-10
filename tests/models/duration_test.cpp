


#include <gtest/gtest.h>

#include <fullscore/models/duration.h>



TEST(DurationTest, can_be_created)
{
   Duration duration(Duration::HALF, 0);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



