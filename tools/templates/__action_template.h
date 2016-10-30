#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class CLASS_NAME : public Base
   {
   private:
      MeasureGrid *measure_grid;

   public:
      CLASS_NAME(MeasureGrid *measure_grid);
      ~CLASS_NAME();

      bool execute() override;
   };
};




