#pragma once



#include <vector>

#include <fullscore/models/pitch.h>



class ProjectionSet
{
public:
   std::vector<Pitch> pitches;
   int extension;

   ProjectionSet(std::vector<Pitch> pitches, int extension);
};



