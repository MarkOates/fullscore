#pragma once



#include <fullscore/models/Pitch.hpp>
#include <iostream>



std::ostream & operator<< (std::ostream &out, Pitch const &t);
std::istream & operator>> (std::istream &in, Pitch &t);



