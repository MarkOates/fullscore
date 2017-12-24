#pragma once



#include <vector>

#include <fullscore/models/Pitch.h>



class IndexSet
{
public:
   std::vector<Pitch> pitches;

   IndexSet(std::vector<Pitch> pitches);

   bool operator==(const IndexSet &other) const;
};



