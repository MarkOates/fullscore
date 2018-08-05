#pragma once



#include <fullscore/actions/Base.h>



class FloatingMeasureCursor;



namespace UI::GridEditor::Actions
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



