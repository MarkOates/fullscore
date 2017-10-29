#pragma once



#include <fullscore/models/plotters/base.h>
#include <fullscore/models/Note.h>



class Grid;



namespace Plotter
{
   class Basic : public Base
   {
   private:
      Grid *grid;
      int barline_num;
      Note note;

   public:
      Basic(Grid *grid, int barline_num, Note note);
      ~Basic();

      bool plot() override;
   };
}



