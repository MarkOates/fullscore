



#include <fullscore/actions/load_grid_action.h>

#include <fullscore/converters/grid_file_converter.h>




Action::LoadMeasureGrid::LoadMeasureGrid(MeasureGrid *grid, std::string filename)
   : Base("load_grid")
   , grid(grid)
   , filename(filename)
{
}




Action::LoadMeasureGrid::~LoadMeasureGrid()
{
}




bool Action::LoadMeasureGrid::execute()
{
   MeasureGridFileConverter grid_file_converter(grid, filename);
   return grid_file_converter.load();
}




