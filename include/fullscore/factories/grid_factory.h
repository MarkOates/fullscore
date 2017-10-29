#pragma once



#include <fullscore/models/grid.h>



class GridFactory
{
public:
   static Grid twinkle_twinkle_little_star();
   static Grid big_score();
   static Grid full_score();
   static Grid string_quartet();
   static Grid testing_template();
   static Grid create(std::string identifier);
};



