#pragma once



#include <fullscore/actions/action_base.h>



class Grid;



namespace Action
{
   class SetReferenceByIDMeasure : public Base
   {
   private:
      Grid *destination_grid;
      int destination_measure_x;
      int destination_staff_y;
      int referenced_measure_id;

   public:
      SetReferenceByIDMeasure(Grid *destination_grid, int destination_measure_x, int destination_staff_y, int referenced_measure_id);
      ~SetReferenceByIDMeasure();

      bool execute() override;
   };
};



