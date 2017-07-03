#pragma once



#include <vector>

#include <Fullscore/models/pitch.h>



class ProjectionSet
{
public:
   int extension;
   std::vector<Pitch> pitches;

   ProjectionSet(std::vector<Pitch> pitches, int extension);
};



