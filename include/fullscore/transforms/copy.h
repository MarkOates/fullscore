#pragma once



#include <fullscore/transforms/base.h>



class MeasureGrid;



namespace Transform
{
   class Copy : public Base
   {
   private:
      MeasureGrid *measure_grid;
      int source_x;
      int source_y;

   public:
      Copy(MeasureGrid *measure_grid, int source_x, int source_y);

      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
};



