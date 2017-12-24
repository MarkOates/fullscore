#pragma once



#include <fullscore/actions/Base.h>
#include <fullscore/models/FloatingMeasureCursor.h>



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



