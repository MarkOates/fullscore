



#include <fullscore/actions/save_measure_grid_action.h>

#include <fullscore/converters/measure_grid_file_converter.h>




SaveMeasureGridAction::SaveMeasureGridAction(MeasureGrid *measure_grid, std::string filename)
   : Base("save_measure_grid")
   , measure_grid(measure_grid)
   , filename(filename)
{
}




SaveMeasureGridAction::~SaveMeasureGridAction()
{
}




bool SaveMeasureGridAction::execute()
{
   // unimplemented
   return false;
}




