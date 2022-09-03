


#include <fullscore/models/plotters/Base.hpp>



Plotter::Base::Base(std::string type)
   : type(type)
{}



Plotter::Base::~Base()
{}



std::string Plotter::Base::get_type()
{
   return type;
}



