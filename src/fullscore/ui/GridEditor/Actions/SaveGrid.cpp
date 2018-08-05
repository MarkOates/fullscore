



#include <fullscore/UI/GridEditor/Actions/SaveGrid.hpp>

#include <fullscore/converters/GridFileConverter.h>




Action::SaveGrid::SaveGrid(Grid *grid, std::string filename)
   : ::Action::Base("save_grid")
   , grid(grid)
   , filename(filename)
{
}




Action::SaveGrid::~SaveGrid()
{
}




bool Action::SaveGrid::execute()
{
   GridFileConverter grid_file_converter(grid, filename);
   return grid_file_converter.save();
}




