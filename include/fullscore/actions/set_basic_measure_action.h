#pragma once



#include <fullscore/actions/base.h>



class Grid;



namespace Action
{
   class SetBasicMeasure : public Base
   {
   private:
      Grid *grid;
      int measure_x;
      int staff_y;

   public:
      SetBasicMeasure(Grid *grid, int measure_x, int staff_y);
      ~SetBasicMeasure();

      bool execute() override;
   };
};



