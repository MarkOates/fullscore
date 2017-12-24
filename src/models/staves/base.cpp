


#include <fullscore/models/measures/Base.h>
#include <fullscore/models/staves/Base.h>
#include <fullscore/models/Staff.h>



Staff::Base::Base(std::string type, std::string name)
   : type(type)
   , id(Staff::next_id++)
   , name(name)
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



