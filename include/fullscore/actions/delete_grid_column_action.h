#pragma once




#include <fullscore/actions/action_base.h>




class Grid;

namespace Action
{
   class DeleteGridColumn : public Base
   {
   private:
      Grid *grid;
      int at_index;

   public:
      DeleteGridColumn(Grid *grid, int at_index);
      ~DeleteGridColumn();

      bool execute() override;
   };
};




