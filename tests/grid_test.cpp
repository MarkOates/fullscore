


#include <gtest/gtest.h>

#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/measures/basic.h>
#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/staves/spacer.h>
#include <fullscore/models/measure.h>
#include <fullscore/models/grid.h>
#include <fullscore/models/note.h>



TEST(GridTest, creates_successfully)
{
   Grid grid(1, 1);
}



TEST(GridTest, returns_the_number_of_staves)
{
   Grid grid(17, 13);
   EXPECT_EQ(13, grid.get_num_staves());
}



TEST(GridTest, returns_the_number_of_measures)
{
   Grid grid(17, 3);
   EXPECT_EQ(17, grid.get_num_measures());
}



TEST(GridTest, sets_and_gets_the_name_of_a_row)
{
   Grid grid(1, 3);

   EXPECT_EQ(true, grid.set_voice_name(0, "Trombone"));
   EXPECT_EQ("Trombone", grid.get_voice_name(0));

   EXPECT_EQ(true, grid.set_voice_name(2, "Euphonium"));
   EXPECT_EQ("Euphonium", grid.get_voice_name(2));

   EXPECT_EQ(true, grid.set_voice_name(2, "Tuba"));
   EXPECT_EQ("Tuba", grid.get_voice_name(2));
}



TEST(GridTest, sets_and_gets_a_measure_to_a_coordinate)
{
   Grid grid(17, 13);

   Measure::Basic *basic_measure = new Measure::Basic();

   EXPECT_TRUE(grid.set_measure(3, 7, basic_measure));

   Measure::Base *retrieved_measure = grid.get_measure(3, 7);
   ASSERT_NE(nullptr, retrieved_measure);
   ASSERT_TRUE(retrieved_measure->is_type(Measure::TYPE_IDENTIFIER_BASIC));

   int expected_id = basic_measure->get_id();
   int returned_id = retrieved_measure->get_id();

   EXPECT_EQ(expected_id, returned_id);
}



TEST(GridTest, can_delete_a_measure)
{
   Grid grid(17, 13);

   Measure::Basic *basic_measure = new Measure::Basic();
   EXPECT_TRUE(grid.set_measure(3, 7, basic_measure));

   Measure::Base *retrieved_measure = grid.get_measure(3, 7);
   ASSERT_NE(nullptr, retrieved_measure);

   grid.delete_measure(3, 7);

   Measure::Base  *expected_null_retrieved_measure = grid.get_measure(3, 7);
   ASSERT_EQ(nullptr, expected_null_retrieved_measure);
}



TEST(GridTest, returns_true_if_coordinates_are_within_the_grid)
{
   Grid grid(17, 13);

   ASSERT_EQ(true, grid.in_grid_range(0, 0));
   ASSERT_EQ(true, grid.in_grid_range(0, 0));
   ASSERT_EQ(true, grid.in_grid_range(grid.get_num_measures()-1, 0));
   ASSERT_EQ(true, grid.in_grid_range(0, grid.get_num_staves()-1));
}



TEST(GridTest, returns_false_if_coordinates_are_outside_the_grid)
{
   Grid grid(17, 13);

   ASSERT_EQ(false, grid.in_grid_range(-1, 0));
   ASSERT_EQ(false, grid.in_grid_range(0, -1));
   ASSERT_EQ(false, grid.in_grid_range(grid.get_num_measures(), 0));
   ASSERT_EQ(false, grid.in_grid_range(0, grid.get_num_staves()));
}



TEST(GridTest, can_insert_a_staff)
{
   Grid grid(1, 3);

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");
   grid.set_voice_name(2, "voice 2");

   grid.insert_staff(new Staff::Instrument(grid.get_num_measures()), 1);
   grid.set_voice_name(1, "inserted voice 1");

   grid.insert_staff(new Staff::Instrument(grid.get_num_measures()), 3);
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
   Grid grid(1, 1);

   ASSERT_EQ(false, grid.insert_staff(nullptr, 1));

   ASSERT_EQ(1, grid.get_num_staves());
}



TEST(GridTest, when_inserting_a_staff_at_index_gte_the_number_of_staves__appends_to_the_end)
{
   Grid grid(1, 2);

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");

   grid.insert_staff(new Staff::Instrument(grid.get_num_measures()), grid.get_num_staves());

   grid.set_voice_name(2, "inserted voice 1");

   grid.insert_staff(new Staff::Instrument(grid.get_num_measures()), 100);

   std::vector<std::string> expected_voice_name_order = { "voice 0", "voice 1", "inserted voice 1", "" };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, when_inserting_a_staff_at_index_lt_zero__inserts_at_the_begingging)
{
   Grid grid(1, 2);

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");

   grid.insert_staff(new Staff::Instrument(grid.get_num_measures()), -100);

   std::vector<std::string> expected_voice_name_order = { "", "voice 0", "voice 1" };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, can_delete_staff)
{
   Grid grid(1, 3);

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
   Grid grid(1, 3);

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");
   grid.set_voice_name(2, "voice 2");

   EXPECT_EQ(false, grid.delete_staff(-1));
   EXPECT_EQ(false, grid.delete_staff(7));

   ASSERT_EQ(3, grid.get_num_staves());
}



TEST(GridTest, can_append_a_staff)
{
   Grid grid(1, 2);

   grid.set_voice_name(0, "voice 0");
   grid.set_voice_name(1, "voice 1");

   grid.append_staff(new Staff::Instrument(grid.get_num_staves()));

   std::vector<std::string> expected_voice_name_order = { "voice 0", "voice 1", "" };

   ASSERT_EQ(expected_voice_name_order.size(), grid.get_num_staves());

   for (int i=0; i<expected_voice_name_order.size(); i++)
      ASSERT_EQ(expected_voice_name_order[i], grid.get_voice_name(i));
}



TEST(GridTest, when_appending_a_nullptr_staff_returns_false)
{
   Grid grid(1, 1);

   ASSERT_EQ(false, grid.append_staff(nullptr));

   ASSERT_EQ(1, grid.get_num_measures());
}



TEST(GridTest, can_insert_a_measure)
{
   Grid grid(3, 1);

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      grid.set_time_signature(i, TimeSignature(3, Duration(Duration::QUARTER)));

   grid.insert_column(1);

   std::vector<TimeSignature> expected_time_signature_order = {
      TimeSignature(3, Duration(Duration::QUARTER)),
      TimeSignature(4, Duration(Duration::QUARTER)),
      TimeSignature(3, Duration(Duration::QUARTER)),
      TimeSignature(3, Duration(Duration::QUARTER)),
   };

   ASSERT_EQ(expected_time_signature_order.size(), grid.get_num_measures());

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      ASSERT_EQ(expected_time_signature_order[i], grid.get_time_signature(i));
}



TEST(GridTest, when_inserting_a_measure_at_index_lt_zero__inserts_at_index_zero)
{
   Grid grid(2, 1);

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      grid.set_time_signature(i, TimeSignature(3, Duration(Duration::QUARTER)));

   grid.insert_column(-999);

   std::vector<TimeSignature> expected_time_signature_order = {
      TimeSignature(4, Duration(Duration::QUARTER)),
      TimeSignature(3, Duration(Duration::QUARTER)),
      TimeSignature(3, Duration(Duration::QUARTER)),
   };

   ASSERT_EQ(expected_time_signature_order.size(), grid.get_num_measures());

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      ASSERT_EQ(expected_time_signature_order[i], grid.get_time_signature(i));
}



TEST(GridTest, when_inserting_a_measure_at_index_gte_size__appends_measure_at_the_end)
{
   Grid grid(2, 1);

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      grid.set_time_signature(i, TimeSignature(3, Duration(Duration::QUARTER)));

   grid.insert_column(grid.get_num_measures());

   grid.set_time_signature(2, TimeSignature(2, Duration(Duration::QUARTER)));

   grid.insert_column(999);

   std::vector<TimeSignature> expected_time_signature_order = {
      TimeSignature(3, Duration(Duration::QUARTER)),
      TimeSignature(3, Duration(Duration::QUARTER)),
      TimeSignature(2, Duration(Duration::QUARTER)),
      TimeSignature(4, Duration(Duration::QUARTER)),
   };

   ASSERT_EQ(expected_time_signature_order.size(), grid.get_num_measures());

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      ASSERT_EQ(expected_time_signature_order[i], grid.get_time_signature(i));
}



TEST(GridTest, can_delete_measure)
{
   Grid grid(4, 1);

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      grid.set_time_signature(i, TimeSignature(i+1, Duration(Duration::QUARTER)));

   grid.delete_column(1);
   grid.delete_column(1);

   std::vector<TimeSignature> expected_time_signature_order = {
      TimeSignature(1, Duration(Duration::QUARTER)),
      TimeSignature(4, Duration(Duration::QUARTER)),
   };

   ASSERT_EQ(expected_time_signature_order.size(), grid.get_num_measures());

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      ASSERT_EQ(expected_time_signature_order[i], grid.get_time_signature(i));
}



TEST(GridTest, when_attempting_to_delete_a_measure_lt_zero_or_gte_num_measures__returns_false_and_does_nothing_to_the_score)
{
   int num_columns_to_test = 4;
   Grid grid(num_columns_to_test, 1);

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      grid.set_time_signature(i, TimeSignature(i+1, Duration(Duration::QUARTER)));

   ASSERT_EQ(false, grid.delete_column(-1));
   ASSERT_EQ(false, grid.delete_column(grid.get_num_measures()));
   ASSERT_EQ(false, grid.delete_column(999));

   ASSERT_EQ(num_columns_to_test, grid.get_num_measures());

   std::vector<TimeSignature> expected_time_signature_order = {
      TimeSignature(1, Duration(Duration::QUARTER)),
      TimeSignature(2, Duration(Duration::QUARTER)),
      TimeSignature(3, Duration(Duration::QUARTER)),
      TimeSignature(4, Duration(Duration::QUARTER)),
   };

   ASSERT_EQ(expected_time_signature_order.size(), grid.get_num_measures());

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      ASSERT_EQ(expected_time_signature_order[i], grid.get_time_signature(i));
}



TEST(GridTest, can_append_a_measure)
{
   Grid grid(1, 1);

   grid.set_time_signature(0, TimeSignature(3, Duration(Duration::QUARTER)));

   grid.append_measure();

   std::vector<TimeSignature> expected_time_signature_order = {
      TimeSignature(3, Duration(Duration::QUARTER)),
      TimeSignature(4, Duration(Duration::QUARTER)),
   };

   ASSERT_EQ(expected_time_signature_order.size(), grid.get_num_measures());

   for (unsigned i=0; i<grid.get_num_measures(); i++)
      ASSERT_EQ(expected_time_signature_order[i], grid.get_time_signature(i));
}



TEST(GridTest, can_get_its_height)
{
   Grid grid(1, 0);

   Staff::Instrument instrument1(1);
   Staff::Instrument instrument2(1);
   Staff::Spacer spacer1(1);
   Staff::Spacer spacer2(1);
   Staff::Spacer spacer3(1);

   grid.append_staff(&instrument1);
   grid.append_staff(&instrument2);
   grid.append_staff(&spacer1);
   grid.append_staff(&spacer2);
   grid.append_staff(&spacer3);

   ASSERT_EQ(3.5, grid.get_height());
}



TEST(GridTest, can_get_a_staff)
{
   Grid grid(1, 0);

   Staff::Instrument instrument1(1);
   Staff::Instrument instrument2(1);
   Staff::Spacer spacer1(1);
   Staff::Spacer spacer2(1);
   Staff::Spacer spacer3(1);

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



TEST(GridTest, when_getting_a_staff_out_of_bounds__returns_nullptr)
{
   Grid grid(0, 1);

   Staff::Instrument instrument1(1);
   Staff::Instrument instrument2(1);
   Staff::Spacer spacer1(1);
   Staff::Spacer spacer2(1);
   Staff::Spacer spacer3(1);

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



TEST(GridTest, can_get_and_set_a_time_signature)
{
   // skip
}



TEST(GridTest, can_get_a_pointer_to_a_time_signature)
{
   // skip
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



