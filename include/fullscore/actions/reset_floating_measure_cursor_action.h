#pragma once



#include <fullscore/actions/base.h>



class FloatingMeasureCursor;



namespace Action
{
   class ResetFloatingMeasureCursor : public Base
   {
   private:
      FloatingMeasureCursor *floating_measure_cursor;

   public:
      ResetFloatingMeasureCursor(FloatingMeasureCursor *floating_measure_cursor);
      ~ResetFloatingMeasureCursor();

      bool execute() override;
   };
};



