#pragma once



#include <fullscore/models/TimeSignature.h>
#include <iostream>



std::ostream & operator<< (std::ostream &out, TimeSignature const &t);
std::istream & operator>> (std::istream &in, TimeSignature &t);



