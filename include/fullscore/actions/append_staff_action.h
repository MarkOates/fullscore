#pragma once



#include <fullscore/actions/base.h>



class Grid;

namespace Action
{
   class AppendStaff : public Base
   {
   private:
      Grid *grid;

   public:
      AppendStaff(Grid *grid);
      ~AppendStaff();

      bool execute() override;
   };
};



