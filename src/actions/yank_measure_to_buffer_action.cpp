



#include <fullscore/actions/yank_measure_to_buffer_action.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/Note.h>




Action::YankMeasureToBuffer::YankMeasureToBuffer(Measure::Basic *yank_measure_buffer, Measure::Base *source_measure)
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
   if (!yank_measure_buffer) throw std::runtime_error("Cannot yank to a nullptr yank_measure_buffer");
   if (!source_measure) throw std::runtime_error("Cannot yank from a nullptr source_measure");

   yank_measure_buffer->set_notes(source_measure->get_notes_copy());
   return true;
}




