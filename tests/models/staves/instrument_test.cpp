


#include <gtest/gtest.h>

#include <fullscore/models/staves/instrument.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/measure.h>



TEST(Staff_InstrumentTest, can_be_created)
{
   Staff::Instrument instrument;
}



TEST(Staff_InstrumentTest, returns_a_staff_height_of_1)
{
   Staff::Instrument instrument;

   ASSERT_EQ(1.0, instrument.get_height());
}



