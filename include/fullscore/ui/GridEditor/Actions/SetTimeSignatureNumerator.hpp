#pragma once



#include <fullscore/actions/Base.h>



class TimeSignature;



namespace UI::GridEditor::Actions
{
   class SetTimeSignatureNumerator : public ::Action::Base
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



