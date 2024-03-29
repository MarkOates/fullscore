#pragma once



#include <fullscore/models/plotters/Base.hpp>
#include <fullscore/models/Note.hpp>
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



