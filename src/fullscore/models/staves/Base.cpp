


#include <fullscore/models/measures/Base.hpp>
#include <fullscore/models/staves/Base.hpp>
#include <fullscore/models/Repositories/StaffRepository.hpp>



Staff::Base::Base(std::string type, std::string name)
   : type(type)
   , id(StaffRepository::next_id++)
   , name(name)
{
   StaffRepository::push_back(this);
}



Staff::Base::~Base()
{
   StaffRepository::remove(id);
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



