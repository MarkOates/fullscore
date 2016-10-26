



#include <fullscore/actions/save_measure_grid_action.h>

#include <fullscore/converters/measure_grid_file_converter.h>




Action::SaveMeasureGridAction::SaveMeasureGridAction(MeasureGrid *measure_grid, std::string filename)
   : Base("save_measure_grid")
   , measure_grid(measure_grid)
   , filename(filename)
{
}




Action::SaveMeasureGridAction::~SaveMeasureGridAction()
{
}




bool Action::SaveMeasureGridAction::execute()
{
   MeasureGridFileConverter measure_grid_file_converter(measure_grid, filename);
   return measure_grid_file_converter.save();
}




