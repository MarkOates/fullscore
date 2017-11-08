


#include <gtest/gtest.h>

#include <fullscore/models/staves/tempo.h>



TEST(Staff_TempoTest, can_be_created)
{
   Staff::Tempo tempo_staff;
}



TEST(Staff_TempoTest, when_setting_a_tempo_marking_with_a_position_lt_0_throws_an_exception)
{
   Staff::Tempo tempo_staff;

   try
   {
      tempo_staff.set_tempo_marking(0, -1, TempoMarking(Duration(Duration::QUARTER), 128));
   }
   catch (std::invalid_argument const &e)
   {
      EXPECT_EQ(e.what(), std::string("Setting a tempo marking to be > 1 or < 0 is not allowed"));
   }
   catch (...)
   {
      FAIL() << "Expected std::invalid_argument";
   }
}



TEST(Staff_TempoTest, when_setting_a_tempo_marking_with_a_position_gt_0_throws_an_exception)
{
   Staff::Tempo tempo_staff;

   try
   {
      tempo_staff.set_tempo_marking(0, 1.1, TempoMarking(Duration(Duration::QUARTER), 128));
   }
   catch (std::invalid_argument const &e)
   {
      EXPECT_EQ(e.what(), std::string("Setting a tempo marking to be > 1 or < 0 is not allowed"));
   }
   catch (...)
   {
      FAIL() << "Expected std::invalid_argument";
   }
}



