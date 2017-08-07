#pragma once



#include <fullscore/actions/action_base.h>



class Grid;



namespace Action
{
   class SetStackMeasure : public Base
   {
   private:
      Grid *grid;
      int measure_x;
      int staff_y;

   public:
      SetStackMeasure(Grid *grid, int measure_x, int staff_y);
      ~SetStackMeasure();

      bool execute() override;
   };
};



