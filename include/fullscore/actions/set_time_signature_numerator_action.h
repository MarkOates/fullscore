#pragma once



#include <fullscore/actions/base.h>



class TimeSignature;



namespace Action
{
   class SetTimeSignatureNumerator : public Base
   {
   private:
      TimeSignature *time_signature;
      int numerator;

   public:
      SetTimeSignatureNumerator(TimeSignature *time_signature, int numerator);
      ~SetTimeSignatureNumerator();

      bool execute() override;
   };
}



