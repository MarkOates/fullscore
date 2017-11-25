#pragma once



#include <fullscore/actions/base.h>



class GridCursor;
class FloatingMeasureCursor;



namespace Action
{
   class SetFloatingMeasureCursorAfterGridCursor : public Base
   {
   private:
      GridCursor *grid_cursor;
      FloatingMeasureCursor *floating_measure_cursor;

   public:
      SetFloatingMeasureCursorAfterGridCursor(GridCursor *grid_cursor, FloatingMeasureCursor *floating_measure_cursor);
      ~SetFloatingMeasureCursorAfterGridCursor();

      bool execute() override;
   };
};



