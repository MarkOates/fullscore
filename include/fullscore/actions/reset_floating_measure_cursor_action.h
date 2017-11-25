#pragma once



#include <fullscore/actions/base.h>



class FloatingMeasureCursor;



namespace Action
{
   class ResetFloatingMeasureCursor : public Base
   {
   private:
      FloatingMeasureCursor *floating_measure_cursor;
      int staff_id;
      int barline_num;

   public:
      ResetFloatingMeasureCursor(FloatingMeasureCursor *floating_measure_cursor, int staff_id, int barline_num);
      ~ResetFloatingMeasureCursor();

      bool execute() override;
   };
};



