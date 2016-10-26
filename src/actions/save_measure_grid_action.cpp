



#include <fullscore/actions/save_measure_grid_action.h>

#include <fullscore/converters/measure_grid_file_converter.h>




Action::SaveMeasureGrid::SaveMeasureGrid(MeasureGrid *measure_grid, std::string filename)
   : Base("save_measure_grid")
   , measure_grid(measure_grid)
   , filename(filename)
{
}




Action::SaveMeasureGrid::~SaveMeasureGrid()
{
}




bool Action::SaveMeasureGrid::execute()
{
   MeasureGridFileConverter measure_grid_file_converter(measure_grid, filename);
   return measure_grid_file_converter.save();
}




