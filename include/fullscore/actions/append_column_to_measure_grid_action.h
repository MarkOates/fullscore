#pragma once



#include <fullscore/actions/action_base.h>



class MeasureGrid;

namespace Action
{
   class AppendColumnToMeasureGrid : public Base
   {
   private:
      MeasureGrid *measure_grid;

   public:
      AppendColumnToMeasureGrid(MeasureGrid *measure_grid);
      ~AppendColumnToMeasureGrid();

      bool execute() override;
   };
};



