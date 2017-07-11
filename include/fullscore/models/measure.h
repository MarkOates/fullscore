#pragma once



#include <vector>

#include <fullscore/transforms/stack.h>



class Note;



class Measure
{
public:
   Transform::Stack *genesis;
   bool refresh();
   bool references_source();

   Measure();

   int extension;
   std::vector<Note> notes;
   Note *operator[](int index);
};



