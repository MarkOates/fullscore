#pragma once



#include <fullscore/actions/Base.h>



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



