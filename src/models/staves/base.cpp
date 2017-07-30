


#include <fullscore/models/measures/base.h>
#include <fullscore/models/staves/base.h>
#include <fullscore/models/staff.h>



Staff::Base::Base(std::string type)
   : type(type)
   , id(Staff::next_id++)
   , name()
   , columns()
{}



Staff::Base::~Base()
{
   if (!columns.empty())
      for (int i=columns.size()-1; i>=0; i--)
         delete columns[i];
}



std::string Staff::Base::get_type()
{
   return type;
}



bool Staff::Base::is_type(std::string type)
{
   return type == type;
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



int Staff::Base::get_num_columns()
{
   return columns.size();
}



