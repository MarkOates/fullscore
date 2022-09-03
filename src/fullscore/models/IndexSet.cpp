


#include <fullscore/models/IndexSet.hpp>



IndexSet::IndexSet(std::vector<Pitch> pitches)
   : pitches(pitches)
{}



bool IndexSet::operator==(const IndexSet &other) const
{
   return other.pitches == pitches;
}



