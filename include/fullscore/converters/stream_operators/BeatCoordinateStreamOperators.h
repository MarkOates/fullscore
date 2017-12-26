#pragma once



#include <fullscore/models/BeatCoordinate.h>
#include <iostream>



std::ostream & operator<< (std::ostream &out, BeatCoordinate const &t);
std::istream & operator>> (std::istream &in, BeatCoordinate &t);



