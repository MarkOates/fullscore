#pragma once



#include <fullscore/actions/action_base.h>



namespace Measure { class Basic; class Base; }
class Grid;



namespace Action
{
   class PasteMeasureFromBufferToGridCoordinates : public Base
   {
   private:
      Measure::Basic *yank_measure_buffer;
      Grid *grid;
      int measure_x;
      int staff_y;

   public:
      PasteMeasureFromBufferToGridCoordinates(Measure::Basic *yank_measure_buffer, Grid *grid, int measure_x, int staff_y);
      ~PasteMeasureFromBufferToGridCoordinates();

      bool execute();
   };
}



