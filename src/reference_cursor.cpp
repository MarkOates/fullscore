


#include <fullscore/reference_cursor.h>

#include <fullscore/models/measure_grid.h>



ReferenceCursor::ReferenceCursor()
   : measure_grid(nullptr)
   , x(0)
   , y(0)
{}



ReferenceCursor::ReferenceCursor(MeasureGrid *measure_grid, int x, int y)
   : measure_grid(measure_grid)
   , x(x)
   , y(y)
{}



void ReferenceCursor::set_position(MeasureGrid *measure_grid, int x, int y)
{
   this->measure_grid = measure_grid;
   this->x = x;
   this->y = y;
}



void ReferenceCursor::set(int x, int y)
{
   this->x = x;
   this->y = y;
}



MeasureGrid *ReferenceCursor::get_measure_grid()
{
   return measure_grid;
}



int ReferenceCursor::get_x()
{
   return x;
}



int ReferenceCursor::get_y()
{
   return y;
}



bool ReferenceCursor::is_on_measure_grid(const MeasureGrid *measure_grid)
{
   return this->measure_grid == measure_grid;
}



void ReferenceCursor::move(int delta_x, int delta_y)
{
   x += delta_x;
   y += delta_y;
}



