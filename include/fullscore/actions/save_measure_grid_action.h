#pragma once




#include <string>
#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class SaveMeasureGridAction : public Base
   {
   private:
      MeasureGrid *measure_grid;
      std::string filename;

   public:
      SaveMeasureGridAction(MeasureGrid *measure_grid, std::string filename);
      ~SaveMeasureGridAction();

      bool execute();
   };
};




