#pragma once



#include <fullscore/actions/action_base.h>



class MeasureGrid;

namespace Action
{
   class AppendColumnToMeasureGrid : public Base
   {
   private:
      MeasureGrid *grid;

   public:
      AppendColumnToMeasureGrid(MeasureGrid *grid);
      ~AppendColumnToMeasureGrid();

      bool execute() override;
   };
};



