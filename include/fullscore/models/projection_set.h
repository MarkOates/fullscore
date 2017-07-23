#pragma once



#include <vector>

#include <fullscore/models/pitch.h>



class ProjectionSet
{
public:
   int extension;
   std::vector<Pitch> pitches;

   ProjectionSet(std::vector<Pitch> pitches, int extension);
};



