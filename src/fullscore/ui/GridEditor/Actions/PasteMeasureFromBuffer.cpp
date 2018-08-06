



#include <fullscore/UI/GridEditor/Actions/PasteMeasureFromBuffer.hpp>

#include <fullscore/models/measures/Basic.h>
#include <fullscore/models/Note.h>
#include <fullscore/UI/GridEditor/Actions.hpp>



namespace UI::GridEditor::Actions
{


PasteMeasureFromBuffer::PasteMeasureFromBuffer(Measure::Base *destination_measure, Measure::Basic *yank_measure_buffer)
   : ::Action::Base(PASTE_MEASURE_FROM_BUFFER_ACTION_IDENTIFIER)
   , yank_measure_buffer(yank_measure_buffer)
   , destination_measure(destination_measure)
{
}




PasteMeasureFromBuffer::~PasteMeasureFromBuffer()
{
}




bool PasteMeasureFromBuffer::execute()
{
   if (!yank_measure_buffer) throw std::runtime_error("Cannot paste from a nullptr yank_measure_buffer");
   if (!destination_measure) throw std::runtime_error("Cannot paste to a nullptr destination_measure");

   destination_measure->set_notes(yank_measure_buffer->get_notes_copy());
   return true;
}


} // namespace UI::GridEditor::Actions


