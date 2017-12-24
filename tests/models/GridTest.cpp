


#include <gtest/gtest.h>

#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/staves/Spacer.h>
#include <fullscore/models/measures/Basic.h>
#include <fullscore/models/Measure.h>
#include <fullscore/models/Grid.h>
#include <fullscore/models/Note.h>



TEST(GridTest, creates_successfully)
{
   Grid grid;
}



TEST(GridTest, returns_the_number_of_barlines)
{
   Grid grid(17);
   EXPECT_EQ(17, grid.get_num_barlines());
}



TEST(GridTest, returns_the_number_of_staves)
{
   Grid grid;
   Staff::Spacer spacer_staff;

   int num_staves = 13;

   for (unsigned i=0; i<num_staves; i++) grid.append_staff(&spacer_staff);

   EXPECT_EQ(num_staves, grid.get_num_staves());
}



TEST(GridTest, DISABLED_sets_and_gets_the_name_of_a_row)
{
   // disabled
}



TEST(GridTest, DISABLED_returns_true_if_coordinates_are_within_the_grid)
{
   // disabled
   // (Grid::in_grid_range())
}



TEST(GridTest, DISABLED_returns_false_if_coordinates_are_outside_the_grid)
{
   // disabled
   // (Grid::in_grid_range())
}



TEST(GridTest, can_insert_a_staff)
{
   Grid grid(1);

   for (unsigned i=0; i<3; i++) grid.append_staff(new Staff::Spacer());

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");
   grid.set_voice_name(2, "voice 2");

   grid.insert_staff(new Staff::Instrument(), 1);
   grid.set_voice_name(1, "inserted voice 1");

   grid.insert_staff(new Staff::Instrument(), 3);
   grid.set_voice_name(3, "inserted voice 2");

   std::vector<std::string> expected_voice_name_order = {
      "voice 0",
      "inserted voice 1",
      "voice 1",
      "inserted voice 2",
      "voice 2",
   };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, when_inserting_a_nullptr_staff_returns_false)
{
   Grid grid;

   ASSERT_EQ(false, grid.insert_staff(nullptr, 1));

   ASSERT_EQ(0, grid.get_num_staves());
}



TEST(GridTest, when_inserting_a_staff_at_index_gte_the_number_of_staves__appends_to_the_end)
{
   Grid grid;

   for (unsigned i=0; i<2; i++) grid.append_staff(new Staff::Spacer());

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");

   grid.insert_staff(new Staff::Instrument(), grid.get_num_staves());

   grid.set_voice_name(2, "inserted voice 1");

   grid.insert_staff(new Staff::Instrument(), 100);

   std::vector<std::string> expected_voice_name_order = { "voice 0", "voice 1", "inserted voice 1", "" };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, when_inserting_a_staff_at_index_lt_zero__inserts_at_the_begingging)
{
   Grid grid;

   for (unsigned i=0; i<2; i++) grid.append_staff(new Staff::Spacer());

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");

   grid.insert_staff(new Staff::Instrument(), -100);

   std::vector<std::string> expected_voice_name_order = { "", "voice 0", "voice 1" };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, can_delete_staff)
{
   Grid grid;

   for (unsigned i=0; i<3; i++) grid.append_staff(new Staff::Spacer());

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");
   grid.set_voice_name(2, "voice 2");

   EXPECT_EQ(true, grid.delete_staff(1));

   std::vector<std::string> expected_voice_name_order = { "voice 0", "voice 2" };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, when_attempting_to_delete_a_staff_that_is_out_of_bounds__returns_false)
{
   Grid grid;

   for (unsigned i=0; i<3; i++) grid.append_staff(new Staff::Spacer());

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");
   grid.set_voice_name(2, "voice 2");

   EXPECT_EQ(false, grid.delete_staff(-1));
   EXPECT_EQ(false, grid.delete_staff(7));

   ASSERT_EQ(3, grid.get_num_staves());
}



TEST(GridTest, can_append_a_staff)
{
   Grid grid;

   for (unsigned i=0; i<2; i++) grid.append_staff(new Staff::Spacer());

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");

   grid.append_staff(new Staff::Instrument());

   std::vector<std::string> expected_voice_name_order = { "voice 0", "voice 1", "" };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, when_appending_a_nullptr_staff_returns_false)
{
   Grid grid(1);

   ASSERT_EQ(false, grid.append_staff(nullptr));

   ASSERT_EQ(1, grid.get_num_barlines());
}



TEST(GridTest, can_get_its_height)
{
   Grid grid;

   Staff::Instrument instrument1;
   Staff::Instrument instrument2;
   Staff::Spacer spacer1;
   Staff::Spacer spacer2;
   Staff::Spacer spacer3;

   grid.append_staff(&instrument1);
   grid.append_staff(&instrument2);
   grid.append_staff(&spacer1);
   grid.append_staff(&spacer2);
   grid.append_staff(&spacer3);

   ASSERT_EQ(3.5, grid.get_height());
}



TEST(GridTest, can_get_a_staff)
{
   Grid grid;

   Staff::Instrument instrument1;
   Staff::Instrument instrument2;
   Staff::Spacer spacer1;
   Staff::Spacer spacer2;
   Staff::Spacer spacer3;

   grid.append_staff(&instrument1);
   grid.append_staff(&instrument2);
   grid.append_staff(&spacer1);
   grid.append_staff(&spacer2);
   grid.append_staff(&spacer3);

   ASSERT_EQ(&instrument1, grid.get_staff(0));
   ASSERT_EQ(&instrument2, grid.get_staff(1));
   ASSERT_EQ(&spacer1, grid.get_staff(2));
   ASSERT_EQ(&spacer2, grid.get_staff(3));
   ASSERT_EQ(&spacer3, grid.get_staff(4));
}



TEST(GridTest, can_get_a_list_of_staves)
{
   Grid grid;

   Staff::Instrument instrument1;
   Staff::Instrument instrument2;
   Staff::Spacer spacer1;
   Staff::Spacer spacer2;
   Staff::Instrument instrument3;

   grid.append_staff(&instrument1);
   grid.append_staff(&instrument2);
   grid.append_staff(&spacer1);
   grid.append_staff(&spacer2);
   grid.append_staff(&instrument3);

   std::vector<Staff::Base *> expected_staves = {
      &instrument1,
      &instrument2,
      &spacer1,
      &spacer2,
      &instrument3
   };

   ASSERT_EQ(expected_staves, grid.get_staves());
}



TEST(GridTest, when_getting_a_staff_out_of_bounds__returns_nullptr)
{
   Grid grid;

   Staff::Instrument instrument1;
   Staff::Instrument instrument2;
   Staff::Spacer spacer1;
   Staff::Spacer spacer2;
   Staff::Spacer spacer3;

   grid.append_staff(&instrument1);
   grid.append_staff(&instrument2);
   grid.append_staff(&spacer1);
   grid.append_staff(&spacer2);
   grid.append_staff(&spacer3);

   ASSERT_EQ(nullptr, grid.get_staff(-1));
   ASSERT_EQ(nullptr, grid.get_staff(-100));
   ASSERT_EQ(nullptr, grid.get_staff(grid.get_num_staves()));
   ASSERT_EQ(nullptr, grid.get_staff(9999));
}



TEST(GridTest, DISABLED_can_get_and_set_a_time_signature)
{
   // skip
}



TEST(GridTest, DISABLED_can_get_a_pointer_to_a_time_signature)
{
   // skip
}



