#pragma once



#include <fullscore/actions/action_base.h>



class Grid;



namespace Action
{
   class SetReferenceByCoordinateMeasure : public Base
   {
   private:
      Grid *destination_grid;
      int destination_measure_x;
      int destination_staff_y;
      Grid *referenced_grid;
      int referenced_measure_x;
      int referenced_staff_y;

   public:
      SetReferenceByCoordinateMeasure(Grid *destination_grid, int destination_measure_x, int destination_staff_y, Grid *referenced_grid, int referenced_measure_x, int referenced_staff_y);
      ~SetReferenceByCoordinateMeasure();

      bool execute() override;
   };
};



