#pragma once



#include <fullscore/models/TimeSignature.hpp>
#include <iostream>



std::ostream & operator<< (std::ostream &out, TimeSignature const &t);
std::istream & operator>> (std::istream &in, TimeSignature &t);



