#pragma once



#include <vector>

#include <fullscore/models/projection_set.h>
#include <fullscore/models/index_set.h>



class PitchProjector
{
private:
   ProjectionSet projection_set;
   IndexSet index_set;

public:
   PitchProjector(ProjectionSet projection_set, IndexSet index_set);
   IndexSet get_projection();
};



