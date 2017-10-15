


#include <fullscore/models/measures/base.h>
#include <fullscore/models/staves/base.h>
#include <fullscore/models/staff.h>



Staff::Base::Base(std::string type)
   : type(type)
   , id(Staff::next_id++)
   , name()
{
   Staff::push_back(this);
}



Staff::Base::~Base()
{
   Staff::remove(id);
}



std::string Staff::Base::get_type()
{
   return type;
}



bool Staff::Base::is_type(std::string type)
{
   return this->type == type;
}



int Staff::Base::get_id()
{
   return id;
}



void Staff::Base::set_name(std::string name)
{
   this->name = name;
}



std::string Staff::Base::get_name()
{
   return name;
}



bool Staff::Base::add_measure(GridHorizontalCoordinate coordinate, Measure::Base *measure)
{
   std::stringstream error_message;
   error_message << "add_measure not implemented for \"" << get_type() << "\" measure type";
   throw std::runtime_error(error_message.str());
}



bool Staff::Base::remove_measure(int measure_id)
{
   std::stringstream error_message;
   error_message << "remove_measure not implemented for \"" << get_type() << "\" measure type";
   throw std::runtime_error(error_message.str());
}



std::vector<std::pair<GridHorizontalCoordinate, Measure::Base *>> Staff::Base::get_measures_in_barline(int barline_num)
{
   return {};
}



std::vector<std::pair<GridHorizontalCoordinate, Measure::Base *>> Staff::Base::get_measures()
{
   return {};
}



int Staff::Base::get_num_measures()
{
   return 0;
}



