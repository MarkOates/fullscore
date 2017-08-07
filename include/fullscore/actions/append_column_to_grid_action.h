#pragma once



#include <fullscore/actions/base.h>



class Grid;

namespace Action
{
   class AppendColumnToGrid : public Base
   {
   private:
      Grid *grid;

   public:
      AppendColumnToGrid(Grid *grid);
      ~AppendColumnToGrid();

      bool execute() override;
   };
};



