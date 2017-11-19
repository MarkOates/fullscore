#pragma once



#include <fullscore/actions/base.h>
#include <fullscore/models/floating_measure_cursor.h>



namespace Action
{
   class MoveFloatingMeasureCursorRight : public Base
   {
   private:
      FloatingMeasureCursor *floating_measure_cursor;

   public:
      MoveFloatingMeasureCursorRight(FloatingMeasureCursor *floating_measure_cursor);
      ~MoveFloatingMeasureCursorRight();

      bool execute() override;
   };
};



