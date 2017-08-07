#pragma once




#include <fullscore/actions/action_base.h>




class MeasureGrid;

namespace Action
{
   class InsertColumn : public Base
   {
   private:
      MeasureGrid *grid;
      int at_index;

   public:
      InsertColumn(MeasureGrid *grid, int at_index);
      ~InsertColumn();

      bool execute() override;
   };
};




