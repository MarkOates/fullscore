#pragma once



#include <fullscore/models/plotters/base.h>
#include <fullscore/models/Note.h>
#include <vector>



class Grid;



namespace Plotter
{
   class Basic : public Base
   {
   private:
      Grid *grid;
      int barline_num;
      std::vector<Note> notes;

   public:
      Basic(Grid *grid, int barline_num, std::vector<Note> notes);
      ~Basic();

      bool plot() override;
   };
}



