


#include <fullscore/UI/GridEditor/Actions/CreateFloatingMeasure.hpp>

#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/UI/GridEditor/Actions.hpp>



Action::CreateFloatingMeasure::CreateFloatingMeasure(GridCoordinate grid_coordinate, int measure_id)
   : ::Action::Base(Action::CREATE_FLOATING_MEASURE_ACTION_IDENTIFIER)
   , grid_coordinate(grid_coordinate)
   , measure_id(measure_id)
   , created_floating_measure_id(-1)
{
}



Action::CreateFloatingMeasure::~CreateFloatingMeasure()
{
}



bool Action::CreateFloatingMeasure::execute()
{
   FloatingMeasure *floating_measure = new FloatingMeasure(grid_coordinate, measure_id);
   created_floating_measure_id = floating_measure->get_id();

   return true;
}



int Action::CreateFloatingMeasure::get_created_floating_measure_id()
{
   return created_floating_measure_id;
}



