


#include <gtest/gtest.h>

#include <fullscore/models/staves/instrument.h>



TEST(Staff_InstrumentTest, can_be_created)
{
   Staff::Instrument instrument(1);
}



TEST(Staff_InstrumentTest, returns_a_staff_height_of_1)
{
   Staff::Instrument instrument(1);

   ASSERT_EQ(1.0, instrument.get_height());
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



