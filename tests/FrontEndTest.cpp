


#include <gtest/gtest.h>



int sum(int a, int b)
{
   return a + b;
}



TEST(FrontEndTest, operates_as_expected)
{
   EXPECT_EQ(sum(1, 2), 3);
   EXPECT_EQ(sum(3, 5), 8);
   EXPECT_EQ(sum(1000, -6543), -5543);
}




