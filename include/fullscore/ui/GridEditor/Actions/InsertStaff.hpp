#pragma once



#include <fullscore/actions/Base.h>



class Grid;

namespace UI::GridEditor::Actions
{
   class InsertStaff : public Action::Base
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



