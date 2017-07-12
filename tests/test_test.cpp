


#include <gtest/gtest.h>



int sum(int a, int b)
{
   return a + b;
}



TEST(SumTest, operates_as_expected)
{
   EXPECT_EQ(sum(1, 2), 3);
   EXPECT_EQ(sum(3, 5), 8);
   EXPECT_EQ(sum(1000, -6543), -5543);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



