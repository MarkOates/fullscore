

#include <fullscore/Cursor.hpp>



namespace fullscore
{


Cursor::Cursor()
   : x(0)
   , y(0)
{
}


Cursor::~Cursor()
{
}


void Cursor::set_x(int x)
{
   this->x = x;
}


void Cursor::set_y(int y)
{
   this->y = y;
}


int Cursor::get_x()
{
   return x;
}


int Cursor::get_y()
{
   return y;
}


} // namespace fullscore


