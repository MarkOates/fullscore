

#include <fullscore/SimpleNothing.hpp>
#include <iostream>
#include <iostream>


namespace fullscore
{


SimpleNothing::SimpleNothing(std::string message)
   : message(message)
{
}


SimpleNothing::~SimpleNothing()
{
}


std::string SimpleNothing::get_message()
{
   return message;
}


void SimpleNothing::output_message()
{
std::cout << "Helloooo" << std::endl;

}
} // namespace fullscore


