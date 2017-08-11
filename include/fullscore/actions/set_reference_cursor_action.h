#pragma once



#include <fullscore/actions/base.h>



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
      ~SetReferenceCursor();

      bool execute() override;
   };
};



