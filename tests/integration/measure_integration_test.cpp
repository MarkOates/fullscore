


#include <gtest/gtest.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/measure.h>



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

   found_measure = Measure::find(measure1.get_id());
   ASSERT_NE(nullptr, found_measure);
   ASSERT_EQ(measure1.get_id(), found_measure->get_id());

   found_measure = Measure::find(measure2.get_id());
   ASSERT_NE(nullptr, found_measure);
   ASSERT_EQ(measure2.get_id(), found_measure->get_id());

   found_measure = Measure::find(measure3.get_id());
   ASSERT_NE(nullptr, found_measure);
   ASSERT_EQ(measure3.get_id(), found_measure->get_id());
}



TEST(MeasureIntegrationTest, when_a_measure_is_removed_cannot_be_found)
{
   TestDerivedClass measure;

   ASSERT_EQ(1, Measure::count());
   ASSERT_EQ(true, Measure::remove(measure.get_id()));

   Measure::remove(measure.get_id());

   ASSERT_EQ(0, Measure::count());
}



TEST(MeasureIntegrationTest, returns_the_count_of_measures)
{
   TestDerivedClass measure1;
   TestDerivedClass measure2;
   TestDerivedClass measure3;

   ASSERT_EQ(3, Measure::count());
}



TEST(MeasureIntegrationTest, when_derived_class_instanciation_is_deleted__is_removed)
{
   TestDerivedClass *measure = new TestDerivedClass();
   delete measure;

   ASSERT_EQ(0, Measure::count());
}



TEST(MeasureIntegrationTest, can_be_destroyed)
{
   TestDerivedClass *measure = new TestDerivedClass();
   ASSERT_EQ(1, Measure::count());

   ASSERT_EQ(true, Measure::destroy(measure->get_id()));
   ASSERT_EQ(0, Measure::count());
}



