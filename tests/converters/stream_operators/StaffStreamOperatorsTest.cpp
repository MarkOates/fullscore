


#include <gtest/gtest.h>

#include <fullscore/converters/stream_operators/StaffStreamOperators.h>
#include <fullscore/models/staves/Base.h>



class MyTestStaff : public Staff::Base
{
public:
   MyTestStaff(std::string name)
      : Base("MyTestStaff", name)
   {}

   float get_height() override
   {
      return 123.0;
   }
};



TEST(StaffStreamOperatorsTest, outputs_to_a_stream_operator)
{
   Staff::Base *staff = new MyTestStaff("Trombone");

   std::stringstream ss;

   ss << staff;

   ASSERT_EQ("0 MyTestStaff Trombone", ss.str());
}



TEST(StaffStreamOperatorsTest, DISABLED_inputs_from_a_stream_operator)
{
   throw std::logic_error{"Not implemented"};
}



TEST(StaffStreamOperatorsTest, DISABLED_stream_operators_are_symmetrical)
{
   throw std::logic_error{"Not implemented"};
}



