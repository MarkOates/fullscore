#pragma once



#include <vector>

#include <fullscore/models/ProjectionSet.hpp>
#include <fullscore/models/IndexSet.hpp>



class PitchProjector
{
private:
   ProjectionSet projection_set;
   IndexSet index_set;

public:
   PitchProjector(ProjectionSet projection_set, IndexSet index_set);
   IndexSet get_projection();
};



