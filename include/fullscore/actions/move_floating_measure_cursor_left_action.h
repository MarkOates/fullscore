#pragma once



#include <fullscore/actions/base.h>
#include <fullscore/models/floating_measure_cursor.h>



namespace Action
{
   class MoveFloatingMeasureCursorLeft : public Base
   {
   private:
      FloatingMeasureCursor *floating_measure_cursor;

   public:
      MoveFloatingMeasureCursorLeft(FloatingMeasureCursor *floating_measure_cursor);
      ~MoveFloatingMeasureCursorLeft();

      bool execute() override;
   };
};



