



#include <fullscore/actions/yank_measure_to_buffer_action.h>

#include <fullscore/models/measure.h>




Action::YankMeasureToBufferAction::YankMeasureToBufferAction(Measure *yank_measure_buffer, Measure *source_measure)
   : Base("yank_measure_to_buffer")
   , yank_measure_buffer(yank_measure_buffer)
   , source_measure(source_measure)
{
}




Action::YankMeasureToBufferAction::~YankMeasureToBufferAction()
{
}




bool Action::YankMeasureToBufferAction::execute()
{
   // unimplemented
   return false;
}




