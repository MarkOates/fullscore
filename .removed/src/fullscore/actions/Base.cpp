



#include <fullscore/actions/Base.hpp>




Action::Base::Base(std::string action_name)
   : action_name(action_name)
{}




Action::Base::~Base()
{}




std::string Action::Base::get_action_name()
{
   return action_name;
}




