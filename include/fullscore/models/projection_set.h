#pragma once



#include <vector>

#include <Fullscore/models/projection_pitch.h>



class ProjectionSet
{
public:
   int extension;
   std::vector<ProjectionPitch> pitches;

   ProjectionSet(std::vector<ProjectionPitch> pitches, int extension);
};



