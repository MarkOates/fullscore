


#include <gtest/gtest.h>

#include <fullscore/actions/set_time_signature_numerator_action.h>
#include <fullscore/models/time_signature.h>



TEST(SetTimeSignatureNumeratorActionTest, sets_the_time_signatures_numerator)
{
   TimeSignature time_signature(4, Duration());

   EXPECT_EQ(4, time_signature.get_numerator());

   Action::SetTimeSignatureNumerator set_time_signature_numerator_action(&time_signature, 3);
   set_time_signature_numerator_action.execute();

   EXPECT_EQ(3, time_signature.get_numerator());
}



TEST(SetTimeSignatureNumeratorActionTest, with_an_invalid_time_signature_raises_an_exception)
{
   try
   {
      Action::SetTimeSignatureNumerator set_time_signature_numerator_action(nullptr, 3);
      set_time_signature_numerator_action.execute();
   }
   catch (std::invalid_argument const &e)
   {
      EXPECT_EQ(e.what(), std::string("Cannot set time signature's numerator on a nullptr time_signature"));
   }
   catch (...)
   {
      FAIL() << "Expected std::invalid_argument";
   }
}



TEST(SetTimeSignatureNumeratorActionTest, with_an_numerator_that_is_greater_than_allowed_raises_an_exception)
{
   try
   {
      TimeSignature time_signature(4, Duration());
      Action::SetTimeSignatureNumerator set_time_signature_numerator_action(&time_signature, TimeSignature::NUMERATOR_MAX+1);
      set_time_signature_numerator_action.execute();
   }
   catch (std::invalid_argument const &e)
   {
      EXPECT_EQ(e.what(), std::string("Cannot set a time signature's numerator to greater than 12"));
   }
   catch (...)
   {
      FAIL() << "Expected std::invalid_argument";
   }
}



TEST(SetTimeSignatureNumeratorActionTest, with_an_numerator_that_is_less_than_allowed_raises_an_exception)
{
   try
   {
      TimeSignature time_signature(4, Duration());
      Action::SetTimeSignatureNumerator set_time_signature_numerator_action(&time_signature, 0);
      set_time_signature_numerator_action.execute();
   }
   catch (std::invalid_argument const &e)
   {
      EXPECT_EQ(e.what(), std::string("Cannot set a time signature's numerator to <= 0"));
   }
   catch (...)
   {
      FAIL() << "Expected std::invalid_argument";
   }
}



