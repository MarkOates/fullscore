#pragma once



#include <fullscore/actions/action_base.h>



class MeasureGrid;



namespace Action
{
   class DeleteMeasure : public Base
   {
   private:
      MeasureGrid *grid;
      int measure_x;
      int staff_y;

   public:
      DeleteMeasure(MeasureGrid *grid, int measure_x, int staff_y);

      bool execute() override;
   };
};



