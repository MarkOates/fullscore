



#include <fullscore/actions/yank_measure_to_buffer_action.h>

#include <fullscore/models/measure.h>
#include <fullscore/models/note.h>




Action::YankMeasureToBuffer::YankMeasureToBuffer(Measure *yank_measure_buffer, Measure *source_measure)
   : Base("yank_measure_to_buffer")
   , yank_measure_buffer(yank_measure_buffer)
   , source_measure(source_measure)
{
}




Action::YankMeasureToBuffer::~YankMeasureToBuffer()
{
}




bool Action::YankMeasureToBuffer::execute()
{
   if (!yank_measure_buffer || !source_measure) return false;
   yank_measure_buffer->notes = source_measure->notes;
   return true;
}




