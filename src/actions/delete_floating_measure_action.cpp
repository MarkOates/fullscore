


#include <fullscore/actions/delete_floating_measure_action.h>

#include <fullscore/models/floating_measure.h>
#include <fullscore/action.h>



Action::DeleteFloatingMeasure::DeleteFloatingMeasure(int floating_measure_id)
   : Base(Action::DELETE_FLOATING_MEASURE_IDENTIFIER)
   , floating_measure_id(floating_measure_id)
{}



Action::DeleteFloatingMeasure::~DeleteFloatingMeasure()
{}



bool Action::DeleteFloatingMeasure::execute()
{
   return FloatingMeasure::destroy(floating_measure_id);
}


