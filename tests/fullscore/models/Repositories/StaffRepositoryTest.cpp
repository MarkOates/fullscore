


#include <gtest/gtest.h>

#include <fullscore/models/Repositories/StaffRepository.hpp>
#include <fullscore/models/staves/Instrument.hpp>
#include <fullscore/models/staves/Spacer.hpp>



TEST(StaffTest, can_find_a_staff_by_id)
{
   Staff::Instrument basic_staff_1;
   Staff::Instrument basic_staff_2;

   ASSERT_EQ(&basic_staff_1, StaffRepository::find(basic_staff_1.get_id()));
   ASSERT_EQ(&basic_staff_2, StaffRepository::find(basic_staff_2.get_id()));
}



TEST(StaffTest, with_a_staff_id_that_is_not_found_returns_nullptr)
{
   ASSERT_EQ(nullptr, StaffRepository::find(-1));
   ASSERT_EQ(nullptr, StaffRepository::find(99999));
}



TEST(StaffTest, with_a_staff_id_that_is_not_found_raises_an_exception__if_the_option_is_set)
{
   ASSERT_THROW(StaffRepository::find(-1, StaffRepository::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
   ASSERT_THROW(StaffRepository::find(99999, StaffRepository::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
}



TEST(StaffTest, can_find_multiple_staves_by_id)
{
   Staff::Instrument basic_staff_1;
   Staff::Instrument basic_staff_2;
   Staff::Instrument basic_staff_3;

   std::vector<int> staff_ids_to_find = { basic_staff_1.get_id(), basic_staff_3.get_id() };
   std::vector<Staff::Base *> expected_returned_staves = { &basic_staff_1, &basic_staff_3 };

   ASSERT_EQ(expected_returned_staves, StaffRepository::find(staff_ids_to_find));
}



TEST(StaffTest, with_a_staff_id_in_a_list_not_found_does_not_include_it_in_the_response_by_default)
{
   Staff::Instrument basic_staff_1;
   Staff::Instrument basic_staff_2;

   std::vector<int> staff_ids_to_find = { basic_staff_1.get_id(), -1, basic_staff_2.get_id(), -2 };
   std::vector<Staff::Base *> expected_returned_staves = { &basic_staff_1, &basic_staff_2 };

   ASSERT_EQ(expected_returned_staves, StaffRepository::find(staff_ids_to_find));
}



TEST(StaffTest, with_a_staff_id_in_a_list_not_found_does_include_it_in_the_response_if_the_option_is_set)
{
   Staff::Instrument basic_staff_1;
   Staff::Instrument basic_staff_2;

   std::vector<int> staff_ids_to_find = { basic_staff_1.get_id(), -1, basic_staff_2.get_id(), -2 };
   std::vector<Staff::Base *> expected_returned_staves = { &basic_staff_1, nullptr, &basic_staff_2, nullptr };

   ASSERT_EQ(expected_returned_staves, StaffRepository::find(staff_ids_to_find, StaffRepository::FIND_OPTION_INCLUDE_NOT_FOUND));
}



TEST(StaffTest, with_a_staff_id_in_a_list_not_found_raises_an_exception_if_the_option_is_set)
{
   Staff::Instrument basic_staff_1;
   Staff::Instrument basic_staff_2;

   std::vector<int> staff_ids_to_find = { basic_staff_1.get_id(), basic_staff_2.get_id(), -1 };

   ASSERT_THROW(StaffRepository::find(staff_ids_to_find, StaffRepository::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
}



TEST(StaffTest, finds_the_first_staff_matching_type)
{
   StaffRepository::destroy_all();

   Staff::Spacer spacer_staff_1;
   Staff::Instrument instrument_staff_1;
   Staff::Spacer spacer_staff_2;
   Staff::Instrument instrument_staff_2;

   ASSERT_EQ(&instrument_staff_1, StaffRepository::find_first_of_type(StaffRepository::TYPE_IDENTIFIER_INSTRUMENT));
}



TEST(StaffTest, DISABLED_has_pool_functions)
{
   // these tests need to be added
}



