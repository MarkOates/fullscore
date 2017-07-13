


#include <fullscore/models/measure/base.h>



Measure2::Base::Base(std::string type)
   : type(type)
{}



Measure2::Base::~Base()
{}



std::string Measure2::Base::get_type()
{
   return type;
}



bool Measure2::Base::is_type(std::string measure_type)
{
   return type == measure_type;
}



