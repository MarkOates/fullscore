#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class AppendStaff : public Base
   {
   private:
      MeasureGrid *measure_grid;

   public:
      AppendStaff(MeasureGrid *measure_grid);
      ~AppendStaff();

      bool execute() override;
   };
};




