



#include <fullscore/actions/paste_measure_from_buffer_action.h>

#include <fullscore/models/measure.h>
#include <fullscore/models/note.h>




Action::PasteMeasureFromBuffer::PasteMeasureFromBuffer(Measure *destination_measure, Measure *yank_measure_buffer)
   : Base("yank_measure_to_buffer")
   , yank_measure_buffer(yank_measure_buffer)
   , destination_measure(destination_measure)
{
}




Action::PasteMeasureFromBuffer::~PasteMeasureFromBuffer()
{
}




bool Action::PasteMeasureFromBuffer::execute()
{
   if (!yank_measure_buffer || !destination_measure) return false;
   destination_measure->notes = yank_measure_buffer->notes;
   return true;
}




