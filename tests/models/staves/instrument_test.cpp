


#include <gtest/gtest.h>

#include <fullscore/models/staves/instrument.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/measure.h>



TEST(Staff_InstrumentTest, can_be_created)
{
   Staff::Instrument instrument(1);
}



TEST(Staff_InstrumentTest, returns_a_staff_height_of_1)
{
   Staff::Instrument instrument(1);

   ASSERT_EQ(1.0, instrument.get_height());
}



TEST(Staff_InstrumentTest, on_construction_all_measures_are_nullptr)
{
   int num_measures = 10;
   Staff::Instrument instrument(num_measures);

   for (unsigned i=0; i<num_measures; i++)
      ASSERT_EQ(nullptr, instrument.get_measure(i));
}



TEST(Staff_InstrumentTest, can_add_a_measure)
{
   Staff::Instrument instrument(1);
   Measure::Basic basic_measure;
   GridHorizontalCoordinate coordinate;
   std::pair<GridHorizontalCoordinate, Measure::Base *> expected_measure_w_coordinate = { coordinate, &basic_measure };

   std::vector<std::pair<GridHorizontalCoordinate, Measure::Base *>> expected_returned_measures = { expected_measure_w_coordinate };

   ASSERT_TRUE(instrument.add_measure(GridHorizontalCoordinate(), &basic_measure));
   ASSERT_EQ(expected_returned_measures, instrument.get_measures());
}



TEST(Staff_InstrumentTest, can_add_a_measure_even_if_outside_the_bounds_of_the_barlines)
{
   Staff::Instrument instrument(1);
   GridHorizontalCoordinate coordinate_1(-999, BeatCoordinate(2, 5, 6));
   Measure::Basic basic_measure_1;
   GridHorizontalCoordinate coordinate_2(11, BeatCoordinate(32, 3, 8));
   Measure::Basic basic_measure_2;
   std::pair<GridHorizontalCoordinate, Measure::Base *> expected_measure_w_coordinate_1 = { coordinate_1, &basic_measure_1 };
   std::pair<GridHorizontalCoordinate, Measure::Base *> expected_measure_w_coordinate_2 = { coordinate_2, &basic_measure_2 };

   std::vector<std::pair<GridHorizontalCoordinate, Measure::Base *>> expected_returned_data = { expected_measure_w_coordinate_1, expected_measure_w_coordinate_2 };

   ASSERT_TRUE(instrument.add_measure(coordinate_1, &basic_measure_1));
   ASSERT_TRUE(instrument.add_measure(coordinate_2, &basic_measure_2));
   ASSERT_EQ(expected_returned_data, instrument.get_measures());
}



TEST(Staff_InstrumentTest, can_remove_a_measure)
{
   Staff::Instrument instrument(1);
   Measure::Basic basic_measure;

   ASSERT_TRUE(instrument.add_measure(GridHorizontalCoordinate(), &basic_measure));
   ASSERT_TRUE(instrument.remove_measure(basic_measure.get_id()));

   ASSERT_EQ(0, instrument.get_num_measures());
}



TEST(Staff_InstrumentTest, removing_a_measure_does_not_delete_it)
{
   Staff::Instrument instrument(1);
   Measure::Basic basic_measure;

   ASSERT_TRUE(instrument.add_measure(GridHorizontalCoordinate(), &basic_measure));
   ASSERT_TRUE(instrument.remove_measure(basic_measure.get_id()));

   Measure::Base *found_measure = nullptr;

   ASSERT_NO_THROW(found_measure = Measure::find(basic_measure.get_id()));
   ASSERT_EQ(found_measure->get_id(), basic_measure.get_id());
}



TEST(Staff_InstrumentTest, can_not_remove_a_measure_that_does_not_belong_to_the_instrument)
{
   Staff::Instrument instrument(1);
   Measure::Basic basic_measure_not_in_instrument;

   ASSERT_FALSE(instrument.remove_measure(basic_measure_not_in_instrument.get_id()));
}



TEST(Staff_InstrumentTest, can_obtain_a_list_of_measures)
{
   Staff::Instrument instrument(4);
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   GridHorizontalCoordinate coordinate_1(0);
   GridHorizontalCoordinate coordinate_2(2, BeatCoordinate(3));

   std::vector<std::pair<GridHorizontalCoordinate, Measure::Base *>> expected_response_data = {
      { coordinate_1, &basic_measure_1 },
      { coordinate_2, &basic_measure_2 },
   };

   for (auto &data : expected_response_data)
      ASSERT_TRUE(instrument.add_measure(std::get<0>(data), std::get<1>(data)));

   ASSERT_EQ(expected_response_data, instrument.get_measures());
}



TEST(Staff_InstrumentTest, can_obtain_the_measures_in_a_barline)
{
   Staff::Instrument instrument(4);
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   GridHorizontalCoordinate coordinate_1(0);
   GridHorizontalCoordinate coordinate_2(2);
   GridHorizontalCoordinate coordinate_3(2, BeatCoordinate(3));
   GridHorizontalCoordinate coordinate_4(3);

   std::vector<std::pair<GridHorizontalCoordinate, Measure::Base *>> expected_response_data = {
      { coordinate_1, &basic_measure_1 },
      { coordinate_2, &basic_measure_1 },
      { coordinate_3, &basic_measure_2 },
      { coordinate_4, &basic_measure_1 }
   };

   for (auto &data : expected_response_data)
      ASSERT_TRUE(instrument.add_measure(std::get<0>(data), std::get<1>(data)));

   std::vector<std::pair<GridHorizontalCoordinate, Measure::Base *>> expected_only_measure_data = {
      { coordinate_2, &basic_measure_1 },
      { coordinate_3, &basic_measure_2 }
   };

   ASSERT_EQ(expected_only_measure_data, instrument.get_measures_in_barline(2));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



