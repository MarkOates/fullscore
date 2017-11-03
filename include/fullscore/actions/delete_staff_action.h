#pragma once



#include <fullscore/actions/base.h>



class Grid;

namespace Action
{
   class DeleteStaff : public Base
   {
   private:
      Grid *grid;
      int at_index;

   public:
      DeleteStaff(Grid *grid, int at_index);
      ~DeleteStaff();

      bool execute() override;
   };
};



