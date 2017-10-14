


#include <gtest/gtest.h>

#include <fullscore/models/staves/base.h>



class DerivedStaff : public Staff::Base
{
public:
   DerivedStaff() : Base("derived_staff") {}

   virtual int get_num_columns() { return 0; }
   virtual float get_height() { return 0; }
   virtual bool set_column(int column_num, Measure::Base *measure) { return true; }
   virtual bool insert_column(int at_index, Measure::Base *measure) { return true; }
   virtual bool erase_column(int at_index) { return true; }
   virtual bool append_column(Measure::Base *measure) { return true; }
   virtual Measure::Base *get_measure(int column_num) { return nullptr; }
   virtual std::vector<Measure::Base *> get_measures_in(int column_num) { return {}; }
};




TEST(Staff_BaseTest, can_be_created)
{
   DerivedStaff derived_staff;
}



TEST(Staff_BaseTest, returns_true_if_is_of_type)
{
   DerivedStaff derived_staff;

   ASSERT_EQ(true, derived_staff.is_type("derived_staff"));
}



TEST(Staff_BaseTest, returns_false_if_is_not_of_type)
{
   DerivedStaff derived_staff;

   ASSERT_EQ(false, derived_staff.is_type("definitely_not_this_type"));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



