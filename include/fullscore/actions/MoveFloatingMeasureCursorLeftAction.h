#pragma once



#include <fullscore/actions/Base.h>
#include <fullscore/models/FloatingMeasureCursor.h>



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


