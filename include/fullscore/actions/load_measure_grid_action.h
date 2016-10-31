#pragma once




#include <string>
#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class LoadMeasureGrid : public Base
   {
   private:
      MeasureGrid *measure_grid;
      std::string filename;

   public:
      LoadMeasureGrid(MeasureGrid *measure_grid, std::string filename);
      ~LoadMeasureGrid();

      bool execute();
   };
};




