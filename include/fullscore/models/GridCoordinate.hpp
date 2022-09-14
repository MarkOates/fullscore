#pragma once



#include <fullscore/models/GridHorizontalCoordinate.hpp>



class GridCoordinate
{
private:
   int staff_id;
   GridHorizontalCoordinate grid_horizontal_coordinate;

public:
   GridCoordinate(int staff_id=0, GridHorizontalCoordinate grid_horizontal_coordinate={});

   void set_staff_id(int staff_id);
   void set_grid_horizontal_coordinate(GridHorizontalCoordinate grid_horizontal_coordinate);

   int get_staff_id();
   GridHorizontalCoordinate get_grid_horizontal_coordinate();

   bool operator==(const GridCoordinate &other) const;
   bool operator!=(const GridCoordinate &other) const;
};



