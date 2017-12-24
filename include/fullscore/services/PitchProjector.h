#pragma once



#include <vector>

#include <fullscore/models/ProjectionSet.h>
#include <fullscore/models/IndexSet.h>



class PitchProjector
{
private:
   ProjectionSet projection_set;
   IndexSet index_set;

public:
   PitchProjector(ProjectionSet projection_set, IndexSet index_set);
   IndexSet get_projection();
};



