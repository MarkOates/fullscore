


#include <fullscore/models/index_set.h>


IndexSet::IndexSet(std::vector<Pitch> pitches)
   : pitches(pitches)
{}



bool IndexSet::operator==(const IndexSet &other) const
{
   return other.pitches == pitches;
}



