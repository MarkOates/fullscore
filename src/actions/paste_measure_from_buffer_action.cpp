



#include <fullscore/actions/paste_measure_from_buffer_action.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/note.h>




Action::PasteMeasureFromBuffer::PasteMeasureFromBuffer(Measure::Base *destination_measure, Measure::Basic *yank_measure_buffer)
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
   if (!yank_measure_buffer) throw std::runtime_error("Cannot yank to a nullptr yank_measure_buffer");
   if (!destination_measure) throw std::runtime_error("Cannot yank from a nullptr destination_measure");

   destination_measure->set_notes(yank_measure_buffer->get_notes_copy());
   return true;
}




