#pragma once



#include <fullscore/actions/Base.h>



class Grid;

namespace UI::GridEditor::Actions
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



