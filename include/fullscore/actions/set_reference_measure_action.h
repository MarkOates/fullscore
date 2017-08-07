#pragma once



#include <fullscore/actions/action_base.h>



class Grid;



namespace Action
{
   class SetReferenceMeasure : public Base
   {
   private:
      Grid *grid;
      int measure_x;
      int staff_y;
      Grid *referenced_grid;
      int referenced_measure_x;
      int referenced_staff_y;

   public:
      SetReferenceMeasure(Grid *grid, int measure_x, int staff_y, Grid *referenced_grid, int referenced_measure_x, int referenced_staff_y);
      ~SetReferenceMeasure();

      bool execute() override;
   };
};



