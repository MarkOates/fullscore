


#include <fullscore/models/reference_cursor.h>

#include <fullscore/models/grid.h>



ReferenceCursor::ReferenceCursor()
   : grid(nullptr)
   , x(0)
   , y(0)
{}



ReferenceCursor::ReferenceCursor(Grid *grid, int x, int y)
   : grid(grid)
   , x(x)
   , y(y)
{}



void ReferenceCursor::set_position(Grid *grid, int x, int y)
{
   this->grid = grid;
   this->x = x;
   this->y = y;
}



void ReferenceCursor::set_coordinates(int x, int y)
{
   this->x = x;
   this->y = y;
}



Grid *ReferenceCursor::get_grid()
{
   return grid;
}



int ReferenceCursor::get_x()
{
   return x;
}



int ReferenceCursor::get_y()
{
   return y;
}



bool ReferenceCursor::is_on_grid(const Grid *grid)
{
   return this->grid == grid;
}



void ReferenceCursor::move(int delta_x, int delta_y)
{
   x += delta_x;
   y += delta_y;
}



bool ReferenceCursor::is_valid()
{
   if (!grid) return false;
   if (x >= grid->get_num_measures()) return false;
   if (x < 0) return false;
   if (y >= grid->get_num_staves()) return false;
   if (y < 0) return false;

   return true;
}



