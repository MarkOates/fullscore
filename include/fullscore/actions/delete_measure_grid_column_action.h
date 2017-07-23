#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class DeleteMeasure : public Base
   {
   private:
      MeasureGrid *measure_grid;
      int at_index;

   public:
      DeleteMeasure(MeasureGrid *measure_grid, int at_index);
      ~DeleteMeasure();

      bool execute() override;
   };
};




