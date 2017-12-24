


#include <fullscore/models/GridCoordinate.h>

#include <fullscore/models/Grid.h>



GridCoordinate::GridCoordinate(int staff_id, GridHorizontalCoordinate grid_horizontal_coordinate)
   : staff_id(staff_id)
   , grid_horizontal_coordinate(grid_horizontal_coordinate)
{}



void GridCoordinate::set_staff_id(int staff_id)
{
   this->staff_id = staff_id;
}



void GridCoordinate::set_grid_horizontal_coordinate(GridHorizontalCoordinate grid_horizontal_coordinate)
{
   this->grid_horizontal_coordinate = grid_horizontal_coordinate;
}



int GridCoordinate::get_staff_id()
{
   return staff_id;
}



GridHorizontalCoordinate GridCoordinate::get_grid_horizontal_coordinate()
{
   return grid_horizontal_coordinate;
}



bool GridCoordinate::operator==(const GridCoordinate &other) const
{
   return (
     staff_id == other.staff_id
     && grid_horizontal_coordinate == other.grid_horizontal_coordinate
  );
}



bool GridCoordinate::operator!=(const GridCoordinate &other) const
{
   return !(*this == other);
}



