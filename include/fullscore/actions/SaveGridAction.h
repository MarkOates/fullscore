#pragma once



#include <string>
#include <fullscore/actions/Base.h>



class Grid;

namespace Action
{
   class SaveGrid : public Base
   {
   private:
      Grid *grid;
      std::string filename;

   public:
      SaveGrid(Grid *grid, std::string filename);
      ~SaveGrid();

      bool execute();
   };
};


