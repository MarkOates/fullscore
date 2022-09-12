


#include <gtest/gtest.h>

#include <fullscore/models/measures/Base.hpp>
#include <fullscore/models/measures/Basic.hpp>
#include <fullscore/models/Repositories/MeasureRepository.hpp>



class TestDerivedClass : public Measure::Base
{
public:
   TestDerivedClass() : Measure::Base("test_derived_class") {}
   virtual int get_num_notes() override { return 0; }
   virtual std::vector<Note> get_notes_copy() override { return {}; }
   virtual bool set_notes(std::vector<Note> notes) override { return true; }
   virtual std::vector<Note> *get_notes_pointer() override { return nullptr; }
};



TEST(MeasureIntegrationTest, can_find_a_measure_by_id)
{
   TestDerivedClass measure1;
   TestDerivedClass measure2;
   TestDerivedClass measure3;

   Measure::Base *found_measure = nullptr;

   found_measure = MeasureRepository::find(measure1.get_id());
   ASSERT_NE(nullptr, found_measure);
   ASSERT_EQ(measure1.get_id(), found_measure->get_id());

   found_measure = MeasureRepository::find(measure2.get_id());
   ASSERT_NE(nullptr, found_measure);
   ASSERT_EQ(measure2.get_id(), found_measure->get_id());

   found_measure = MeasureRepository::find(measure3.get_id());
   ASSERT_NE(nullptr, found_measure);
   ASSERT_EQ(measure3.get_id(), found_measure->get_id());
}



TEST(MeasureIntegrationTest, when_a_measure_is_removed_cannot_be_found)
{
   TestDerivedClass measure;

   ASSERT_EQ(1, MeasureRepository::count());
   ASSERT_EQ(true, MeasureRepository::remove(measure.get_id()));

   MeasureRepository::remove(measure.get_id());

   ASSERT_EQ(0, MeasureRepository::count());
}



TEST(MeasureIntegrationTest, returns_the_count_of_measures)
{
   TestDerivedClass measure1;
   TestDerivedClass measure2;
   TestDerivedClass measure3;

   ASSERT_EQ(3, MeasureRepository::count());
}



TEST(MeasureIntegrationTest, when_derived_class_instanciation_is_deleted__is_removed)
{
   TestDerivedClass *measure = new TestDerivedClass();
   delete measure;

   ASSERT_EQ(0, MeasureRepository::count());
}



TEST(MeasureIntegrationTest, can_be_destroyed)
{
   TestDerivedClass *measure = new TestDerivedClass();
   ASSERT_EQ(1, MeasureRepository::count());

   ASSERT_EQ(true, MeasureRepository::destroy(measure->get_id()));
   ASSERT_EQ(0, MeasureRepository::count());
}



#include <gtest/gtest.h>

#include <fullscore/models/Repositories/MeasureRepository.hpp>
#include <fullscore/models/measures/Basic.hpp>



TEST(MeasureRepositoryTest, can_find_a_measure_by_id)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   ASSERT_EQ(&basic_measure_1, MeasureRepository::find(basic_measure_1.get_id()));
   ASSERT_EQ(&basic_measure_2, MeasureRepository::find(basic_measure_2.get_id()));
}



TEST(MeasureRepositoryTest, with_a_measure_id_that_is_not_found_returns_nullptr)
{
   ASSERT_EQ(nullptr, MeasureRepository::find(-1));
   ASSERT_EQ(nullptr, MeasureRepository::find(99999));
}



TEST(MeasureRepositoryTest, with_a_measure_id_that_is_not_found_raises_an_exception__if_the_option_is_set)
{
   ASSERT_THROW(MeasureRepository::find(-1, MeasureRepository::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
   ASSERT_THROW(MeasureRepository::find(99999, MeasureRepository::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
}



TEST(MeasureRepositoryTest, can_find_multiple_measures_by_id)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;
   Measure::Basic basic_measure_3;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), basic_measure_3.get_id() };
   std::vector<Measure::Base *> expected_returned_measures = { &basic_measure_1, &basic_measure_3 };

   ASSERT_EQ(expected_returned_measures, MeasureRepository::find(measure_ids_to_find));
}



TEST(MeasureRepositoryTest, with_a_measure_id_in_a_list_not_found_does_not_include_it_in_the_response_by_default)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), -1, basic_measure_2.get_id(), -2 };
   std::vector<Measure::Base *> expected_returned_measures = { &basic_measure_1, &basic_measure_2 };

   ASSERT_EQ(expected_returned_measures, MeasureRepository::find(measure_ids_to_find));
}



TEST(MeasureRepositoryTest, with_a_measure_id_in_a_list_not_found_does_include_it_in_the_response_if_the_option_is_set)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), -1, basic_measure_2.get_id(), -2 };
   std::vector<Measure::Base *> expected_returned_measures = { &basic_measure_1, nullptr, &basic_measure_2, nullptr };

   ASSERT_EQ(expected_returned_measures, MeasureRepository::find(measure_ids_to_find, MeasureRepository::FIND_OPTION_INCLUDE_NOT_FOUND));
}



TEST(MeasureRepositoryTest, with_a_measure_id_in_a_list_not_found_raises_an_exception_if_the_option_is_set)
{
   Measure::Basic basic_measure_1;
   Measure::Basic basic_measure_2;

   std::vector<int> measure_ids_to_find = { basic_measure_1.get_id(), basic_measure_2.get_id(), -1 };

   ASSERT_THROW(MeasureRepository::find(measure_ids_to_find, MeasureRepository::FIND_OPTION_RAISE_NOT_FOUND), std::runtime_error);
}



TEST(MeasureRepositoryTest, DISABLED_has_pool_functions)
{
   // these tests need to be added
}



