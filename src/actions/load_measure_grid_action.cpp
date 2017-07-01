



#include <fullscore/actions/load_measure_grid_action.h>

#include <fullscore/converters/measure_grid_file_converter.h>




Action::LoadMeasureGrid::LoadMeasureGrid(MeasureGrid *measure_grid, std::string filename)
   : Base("load_measure_grid")
   , measure_grid(measure_grid)
   , filename(filename)
{
}




Action::LoadMeasureGrid::~LoadMeasureGrid()
{
}




bool Action::LoadMeasureGrid::execute()
{
   MeasureGridFileConverter measure_grid_file_converter(measure_grid, filename);
   return measure_grid_file_converter.load();
}




