#pragma once



#include <vector>

#include <fullscore/models/Pitch.hpp>



class ProjectionSet
{
public:
   std::vector<Pitch> pitches;
   int extension;

   ProjectionSet(std::vector<Pitch> pitches, int extension);
};



