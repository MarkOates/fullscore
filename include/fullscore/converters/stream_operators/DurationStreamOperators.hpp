#pragma once



#include <fullscore/models/Duration.hpp>
#include <iostream>



std::ostream & operator<< (std::ostream &out, Duration const &t);
std::istream & operator>> (std::istream &in, Duration &t);



