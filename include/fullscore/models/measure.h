#pragma once



#include <vector>

#include <fullscore/transforms/stack.h>



class Note;



class Measure
{
public:
   Transform::Stack *genesis;
   void end_of_the_line();

   Measure();

   int extension;
   std::vector<Note> notes;
   Note *operator[](int index);
};



