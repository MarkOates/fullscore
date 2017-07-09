#ifndef __FULLSCORE_MEASURE_HEADER
#define __FULLSCORE_MEASURE_HEADER




#include <vector>




class Note;




class Measure
{
public:
   int extension;
	std::vector<Note> notes;
   Note *operator[](int index);
};




#endif
