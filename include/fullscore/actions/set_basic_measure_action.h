#pragma once



#include <fullscore/actions/action_base.h>



class MeasureGrid;



namespace Action
{
   class SetBasicMeasure : public Base
   {
   private:
      MeasureGrid *grid;
      int measure_x;
      int staff_y;

   public:
      SetBasicMeasure(MeasureGrid *grid, int measure_x, int staff_y);
      ~SetBasicMeasure();

      bool execute() override;
   };
};



