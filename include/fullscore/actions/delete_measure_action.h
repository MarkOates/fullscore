#pragma once



#include <fullscore/actions/base.h>



class Grid;

namespace Action
{
   class DeleteMeasure : public Base
   {
   private:
      Grid *grid;
      int measure_x;
      int staff_y;

   public:
      DeleteMeasure(Grid *grid, int measure_x, int staff_y);
      ~DeleteMeasure();

      bool execute() override;
   };
};



