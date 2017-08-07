



#include <fullscore/actions/save_grid_action.h>

#include <fullscore/converters/grid_file_converter.h>




Action::SaveMeasureGrid::SaveMeasureGrid(MeasureGrid *grid, std::string filename)
   : Base("save_grid")
   , grid(grid)
   , filename(filename)
{
}




Action::SaveMeasureGrid::~SaveMeasureGrid()
{
}




bool Action::SaveMeasureGrid::execute()
{
   MeasureGridFileConverter grid_file_converter(grid, filename);
   return grid_file_converter.save();
}




