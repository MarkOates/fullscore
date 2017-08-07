#pragma once



#include <fullscore/actions/action_base.h>



class MeasureGrid;



namespace Action
{
   class SetReferenceMeasure : public Base
   {
   private:
      MeasureGrid *grid;
      int measure_x;
      int staff_y;
      MeasureGrid *referenced_grid;
      int referenced_measure_x;
      int referenced_staff_y;

   public:
      SetReferenceMeasure(MeasureGrid *grid, int measure_x, int staff_y, MeasureGrid *referenced_grid, int referenced_measure_x, int referenced_staff_y);
      ~SetReferenceMeasure();

      bool execute() override;
   };
};



