#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class DeleteMeasureGridColumn : public Base
   {
   private:
      MeasureGrid *grid;
      int at_index;

   public:
      DeleteMeasureGridColumn(MeasureGrid *grid, int at_index);
      ~DeleteMeasureGridColumn();

      bool execute() override;
   };
};




