#pragma once



#include <string>
#include <fullscore/actions/base.h>



class Grid;

namespace Action
{
   class LoadGrid : public Base
   {
   private:
      Grid *grid;
      std::string filename;

   public:
      LoadGrid(Grid *grid, std::string filename);
      ~LoadGrid();

      bool execute();
   };
};



