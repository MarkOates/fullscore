#pragma once



#include <fullscore/actions/action_base.h>



namespace Measure { class Basic; class Base; }
class MeasureGrid;



namespace Action
{
   class PasteMeasureFromBufferToMeasureGridCoordinates : public Base
   {
   private:
      Measure::Basic *yank_measure_buffer;
      MeasureGrid *measure_grid;
      int measure_x;
      int staff_y;

   public:
      PasteMeasureFromBufferToMeasureGridCoordinates(Measure::Basic *yank_measure_buffer, MeasureGrid *measure_grid, int measure_x, int staff_y);
      ~PasteMeasureFromBufferToMeasureGridCoordinates();

      bool execute();
   };
}



