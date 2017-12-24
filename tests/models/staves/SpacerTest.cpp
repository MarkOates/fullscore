


#include <gtest/gtest.h>

#include <fullscore/models/staves/Spacer.h>



TEST(Staff_SpacerTest, can_be_created)
{
   Staff::Spacer spacer;
}



TEST(Staff_SpacerTest, returns_a_staff_height_of_0_5)
{
   Staff::Spacer spacer;

   ASSERT_EQ(0.5, spacer.get_height());
}



