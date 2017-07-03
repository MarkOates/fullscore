#pragma once



#include <vector>

#include <Fullscore/models/pitch.h>



class IndexSet
{
public:
   std::vector<Pitch> pitches;

   IndexSet(std::vector<Pitch> pitches);

   bool operator==(const IndexSet &other) const;
};



