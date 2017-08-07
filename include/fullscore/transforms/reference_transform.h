#pragma once



#include <fullscore/transforms/base.h>



class MeasureGrid;



namespace Transform
{
   class Reference : public Base
   {
   private:
      MeasureGrid *grid;
      int source_x;
      int source_y;

   public:
      Reference(MeasureGrid *grid, int source_x, int source_y);

      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
};



