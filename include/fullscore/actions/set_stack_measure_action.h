#pragma once



#include <fullscore/actions/action_base.h>



class MeasureGrid;



namespace Action
{
   class SetStackMeasure : public Base
   {
   private:
      MeasureGrid *measure_grid;
      int measure_x;
      int staff_y;

   public:
      SetStackMeasure(MeasureGrid *measure_grid, int measure_x, int staff_y);
      ~SetStackMeasure();

      bool execute() override;
   };
};



