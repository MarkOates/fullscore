#pragma once



#include <fullscore/actions/action_base.h>



class Grid;
class ReferenceCursor;



namespace Action
{
   class SetReferenceCursor : public Base
   {
   private:
      ReferenceCursor *reference_cursor;
      Grid *grid;
      int measure_x;
      int staff_y;

   public:
      SetReferenceCursor(ReferenceCursor *reference_cursor, Grid *grid, int measure_x, int staff_y);

      bool execute() override;
   };
};



