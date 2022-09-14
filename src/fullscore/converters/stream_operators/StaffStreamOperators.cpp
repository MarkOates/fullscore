


#include <fullscore/converters/stream_operators/StaffStreamOperators.hpp>



std::ostream & operator<< (std::ostream &out, Staff::Base* const &t)
{
   out << t->get_id() << " " << t->get_type() << " " << t->get_name();
   return out;
}



std::istream & operator>> (std::istream &in, Staff::Base* &t)
{
   throw std::logic_error{"Not implemented"};
   return in;
}



