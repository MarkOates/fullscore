#pragma once



#include <fullscore/models/BeatCoordinate.hpp>
#include <iostream>



std::ostream & operator<< (std::ostream &out, BeatCoordinate const &t);
std::istream & operator>> (std::istream &in, BeatCoordinate &t);



