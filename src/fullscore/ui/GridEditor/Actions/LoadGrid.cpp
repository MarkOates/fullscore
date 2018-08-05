



#include <fullscore/UI/GridEditor/Actions/LoadGrid.hpp>

#include <fullscore/converters/GridFileConverter.h>




Action::LoadGrid::LoadGrid(Grid *grid, std::string filename)
   : ::Action::Base("load_grid")
   , grid(grid)
   , filename(filename)
{
}




Action::LoadGrid::~LoadGrid()
{
}




bool Action::LoadGrid::execute()
{
   GridFileConverter grid_file_converter(grid, filename);
   return grid_file_converter.load();
}




