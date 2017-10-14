


#include <fullscore/models/grid_coordinate.h>

#include <fullscore/models/grid.h>



GridCoordinate::GridCoordinate(Grid *grid, int staff_id, int barline_num, int beat_num)
   : grid(grid)
   , staff_id(staff_id)
   , barline_num(barline_num)
   , beat_num(beat_num)
{}



void GridCoordinate::set_grid(Grid *grid)
{
   this->grid = grid;
}



void GridCoordinate::set_staff_id(int staff_id)
{
   this->staff_id = staff_id;
}



void GridCoordinate::set_barline_num(int barline_num)
{
   this->barline_num = barline_num;
}



void GridCoordinate::set_beat_num(int beat_num)
{
   this->beat_num = beat_num;
}



Grid *GridCoordinate::get_grid()
{
   return grid;
}



int GridCoordinate::get_staff_id()
{
   return staff_id;
}



int GridCoordinate::get_barline_num()
{
   return barline_num;
}



int GridCoordinate::get_beat_num()
{
   return beat_num;
}



bool GridCoordinate::operator==(const GridCoordinate &other) const
{
   return (
     grid == other.grid
     && staff_id == other.staff_id
     && barline_num == other.barline_num
     && beat_num == other.beat_num
  );
}



bool GridCoordinate::operator!=(const GridCoordinate &other) const
{
   return !(*this == other);
}



