#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class DeleteStaff : public Base
   {
   private:
      MeasureGrid *measure_grid;
      int at_index;

   public:
      DeleteStaff(MeasureGrid *measure_grid, int at_index);
      ~DeleteStaff();

      bool execute() override;
   };
};




