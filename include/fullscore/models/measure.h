#pragma once



#include <vector>



class Note;



class Measure
{
public:
   int extension;
   std::vector<Note> notes;
   Note *operator[](int index);
};



