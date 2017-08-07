#pragma once




#include <string>
#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class SaveMeasureGrid : public Base
   {
   private:
      MeasureGrid *measure_grid;
      std::string filename;

   public:
      SaveMeasureGrid(MeasureGrid *measure_grid, std::string filename);
      ~SaveMeasureGrid();

      bool execute();
   };
};




