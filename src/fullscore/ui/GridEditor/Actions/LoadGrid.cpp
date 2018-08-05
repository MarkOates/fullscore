



#include <fullscore/UI/GridEditor/Actions/LoadGrid.hpp>

#include <fullscore/converters/GridFileConverter.h>



namespace UI::GridEditor::Actions
{


LoadGrid::LoadGrid(Grid *grid, std::string filename)
   : ::Action::Base("load_grid")
   , grid(grid)
   , filename(filename)
{
}




LoadGrid::~LoadGrid()
{
}




bool LoadGrid::execute()
{
   GridFileConverter grid_file_converter(grid, filename);
   return grid_file_converter.load();
}


} // namespace UI::GridEditor::Actions


