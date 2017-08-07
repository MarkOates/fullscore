#pragma once



#include <fullscore/models/grid.h>



class MeasureGridFactory
{
public:
   static MeasureGrid twinkle_twinkle_little_star();
   static MeasureGrid big_score();
   static MeasureGrid full_score();
   static MeasureGrid create(std::string identifier);
};



