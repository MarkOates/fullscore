


#include <fullscore/UI/GridEditor/Actions/DeleteFloatingMeasure.hpp>

#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/UI/GridEditor/Actions.hpp>


namespace UI::GridEditor::Actions
{


DeleteFloatingMeasure::DeleteFloatingMeasure(int floating_measure_id)
   : ::Action::Base(DELETE_FLOATING_MEASURE_IDENTIFIER)
   , floating_measure_id(floating_measure_id)
{}



DeleteFloatingMeasure::~DeleteFloatingMeasure()
{}



bool DeleteFloatingMeasure::execute()
{
   return FloatingMeasure::destroy(floating_measure_id);
}


} // namespace UI::GridEditor::Actions

