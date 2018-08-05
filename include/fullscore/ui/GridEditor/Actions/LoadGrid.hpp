#pragma once



#include <string>
#include <fullscore/actions/Base.h>



class Grid;

namespace UI::GridEditor::Actions
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



