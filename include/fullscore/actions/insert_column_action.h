#pragma once



#include <fullscore/actions/base.h>



class Grid;

namespace Action
{
   class InsertColumn : public Base
   {
   private:
      Grid *grid;
      int at_index;

   public:
      InsertColumn(Grid *grid, int at_index);
      ~InsertColumn();

      bool execute() override;
   };
};



