#pragma once



#include <fullscore/models/staves/Base.hpp>
#include <iostream>



std::ostream & operator<< (std::ostream &out, Staff::Base* const &t);
std::istream & operator>> (std::istream &in, Staff::Base* &t);



