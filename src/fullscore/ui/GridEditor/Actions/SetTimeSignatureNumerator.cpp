


#include <fullscore/UI/GridEditor/Actions/SetTimeSignatureNumerator.hpp>

#include <fullscore/models/TimeSignature.h>



Action::SetTimeSignatureNumerator::SetTimeSignatureNumerator(TimeSignature *time_signature, int numerator)
   : ::Action::Base("set_time_signature_numerator")
   , time_signature(time_signature)
   , numerator(numerator)
{}



Action::SetTimeSignatureNumerator::~SetTimeSignatureNumerator()
{}



bool Action::SetTimeSignatureNumerator::execute()
{
   if (!time_signature) throw std::invalid_argument("Cannot set time signature's numerator on a nullptr time_signature");
   if (numerator <= 0) throw std::invalid_argument("Cannot set a time signature's numerator to <= 0");
   if (numerator > TimeSignature::NUMERATOR_MAX)
   {
      std::stringstream error_message;
      error_message << "Cannot set a time signature's numerator to greater than " << TimeSignature::NUMERATOR_MAX;
      throw std::invalid_argument(error_message.str());
   }

   return time_signature->set_numerator(numerator);
}



