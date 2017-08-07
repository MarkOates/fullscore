#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class AppendStaff : public Base
   {
   private:
      MeasureGrid *grid;

   public:
      AppendStaff(MeasureGrid *grid);
      ~AppendStaff();

      bool execute() override;
   };
};




