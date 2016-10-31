#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class AppendMeasure : public Base
   {
   private:
      MeasureGrid *measure_grid;

   public:
      AppendMeasure(MeasureGrid *measure_grid);
      ~AppendMeasure();

      bool execute() override;
   };
};




