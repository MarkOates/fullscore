#pragma once



#include <fullscore/models/Note.h>
#include <iostream>



std::ostream & operator<< (std::ostream &out, Note const &t);
std::istream & operator>> (std::istream &in, Note &t);



