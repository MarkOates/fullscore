


#include <fullscore/models/measures/base.h>



Measure::Base::Base(std::string type)
   : type(type)
{}



Measure::Base::~Base()
{}



std::string Measure::Base::get_type()
{
   return type;
}



bool Measure::Base::is_type(std::string measure_type)
{
   return type == measure_type;
}



