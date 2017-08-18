



#include <fullscore/actions/yank_grid_measure_to_buffer_action.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/Note.h>
#include <fullscore/action.h>




Action::YankGridMeasureToBuffer::YankGridMeasureToBuffer(Measure::Basic *yank_measure_buffer, Measure::Base *source_measure)
   : Base(YANK_GRID_MEASURE_TO_BUFFER_ACTION_IDENTIFIER)
   , yank_measure_buffer(yank_measure_buffer)
   , source_measure(source_measure)
{
}




Action::YankGridMeasureToBuffer::~YankGridMeasureToBuffer()
{
}




bool Action::YankGridMeasureToBuffer::execute()
{
   if (!yank_measure_buffer) throw std::runtime_error("Cannot yank to a nullptr yank_grid_measure_buffer");
   if (!source_measure) throw std::runtime_error("Cannot yank from a nullptr source_measure");

   yank_measure_buffer->set_notes(source_measure->get_notes_copy());
   return true;
}




