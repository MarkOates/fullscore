#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class InsertStaff : public Base
   {
   private:
      MeasureGrid *measure_grid;
      int at_index;

   public:
      InsertStaff(MeasureGrid *measure_grid, int at_index);
      ~InsertStaff();

      bool execute() override;
   };
};




