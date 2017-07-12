


#include <gtest/gtest.h>

#include <fullscore/models/measure/base.h>



class TestDerivedClass : public Measure::Base
{
public:
   TestDerivedClass() : Measure::Base("test_derived_class") {}
   virtual std::vector<Note> get_notes() override
   {
      std::vector<Note> notes;
      return notes;
   }
};



TEST(MeasureBaseTest, can_be_created)
{
   TestDerivedClass measure_base;
}



TEST(MeasureBaseTest, returns_its_type)
{
   TestDerivedClass measure_base;
   ASSERT_EQ("test_derived_class", measure_base.get_type());
}



TEST(MeasureBaseTest, returns_true_if_matches_type)
{
   TestDerivedClass measure_base;
   ASSERT_EQ(true, measure_base.is_type("test_derived_class"));
}



TEST(MeasureBaseTest, returns_false_if_does_not_matche_type)
{
   TestDerivedClass measure_base;
   ASSERT_EQ(false, measure_base.is_type("definitely_not_this_type"));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



