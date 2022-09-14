#pragma once



#include <fullscore/models/Note.hpp>
#include <iostream>



std::ostream & operator<< (std::ostream &out, Note const &t);
std::istream & operator>> (std::istream &in, Note &t);



