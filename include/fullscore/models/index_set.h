#pragma once



#include <vector>

#include <Fullscore/models/projection_pitch.h>



class IndexSet
{
public:
   std::vector<ProjectionPitch> pitches;

   IndexSet(std::vector<ProjectionPitch> pitches);

   bool operator==(const IndexSet &other) const;
};



