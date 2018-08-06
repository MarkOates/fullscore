



#include <fullscore/UI/GridEditor/Actions/SaveGrid.hpp>

#include <fullscore/converters/GridFileConverter.h>



namespace UI::GridEditor::Actions
{


SaveGrid::SaveGrid(Grid *grid, std::string filename)
   : ::Action::Base("save_grid")
   , grid(grid)
   , filename(filename)
{
}




SaveGrid::~SaveGrid()
{
}




bool SaveGrid::execute()
{
   GridFileConverter grid_file_converter(grid, filename);
   return grid_file_converter.save();
}


} // namespace UI::GridEditor::Actions


