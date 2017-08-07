#pragma once




#include <fullscore/actions/action_base.h>




class Grid;

namespace Action
{
   class InsertStaff : public Base
   {
   private:
      Grid *grid;
      int at_index;

   public:
      InsertStaff(Grid *grid, int at_index);
      ~InsertStaff();

      bool execute() override;
   };
};




