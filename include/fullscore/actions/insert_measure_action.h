#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class InsertMeasure : public Base
   {
   private:
      MeasureGrid *measure_grid;
      int at_index;

   public:
      InsertMeasure(MeasureGrid *measure_grid, int at_index);
      ~InsertMeasure();

      bool execute() override;
   };
};




