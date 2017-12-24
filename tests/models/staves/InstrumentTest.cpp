


#include <gtest/gtest.h>

#include <fullscore/models/staves/Instrument.h>

#include <fullscore/models/measures/Basic.h>
#include <fullscore/models/Measure.h>
#include <fullscore/models/Staff.h>



TEST(Staff_InstrumentTest, can_be_created)
{
   Staff::Instrument instrument;
}



TEST(Staff_InstrumentTest, returns_a_staff_height_of_1)
{
   Staff::Instrument instrument;

   ASSERT_EQ(1.0, instrument.get_height());
}



TEST(Staff_InstrumentTest, has_the_expected_type)
{
   Staff::Instrument instrument;

   ASSERT_TRUE(instrument.is_type(Staff::TYPE_IDENTIFIER_INSTRUMENT));
}



TEST(Staff_InstrumentTest, has_attributes)
{
   Staff::Instrument instrument;
   instrument.attributes.set("hello", "world");

   ASSERT_EQ("world", instrument.attributes.get("hello"));
}



