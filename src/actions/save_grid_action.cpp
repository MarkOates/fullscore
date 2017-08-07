



#include <fullscore/actions/save_grid_action.h>

#include <fullscore/converters/grid_file_converter.h>




Action::SaveGrid::SaveGrid(Grid *grid, std::string filename)
   : Base("save_grid")
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




