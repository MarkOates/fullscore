#pragma once



#include <fullscore/transforms/base.h>



class Grid;



namespace Transform
{
   class Reference : public Base
   {
   private:
      Grid *grid;
      int source_x;
      int source_y;

   public:
      Reference(Grid *grid, int source_x, int source_y);

      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
};



