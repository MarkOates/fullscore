



#include <fullscore/UI/GridEditor/Actions/YankGridMeasureToBuffer.hpp>

#include <fullscore/models/measures/Basic.h>
#include <fullscore/models/Note.h>
#include <fullscore/UI/GridEditor/Actions.hpp>


namespace UI::GridEditor::Actions
{


YankGridMeasureToBuffer::YankGridMeasureToBuffer(Measure::Basic *yank_measure_buffer, Measure::Base *source_measure)
   : ::Action::Base(YANK_GRID_MEASURE_TO_BUFFER_ACTION_IDENTIFIER)
   , yank_measure_buffer(yank_measure_buffer)
   , source_measure(source_measure)
{
}




YankGridMeasureToBuffer::~YankGridMeasureToBuffer()
{
}




bool YankGridMeasureToBuffer::execute()
{
   if (!yank_measure_buffer) throw std::runtime_error("Cannot yank to a nullptr yank_grid_measure_buffer");
   if (!source_measure) throw std::runtime_error("Cannot yank from a nullptr source_measure");

   yank_measure_buffer->set_notes(source_measure->get_notes_copy());
   return true;
}


} // namespace UI::GridEditor::Actions


