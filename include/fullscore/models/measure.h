#pragma once



#include <vector>
#include <fullscore/models/note.h>



namespace Measure
{
   class Base;

   extern std::vector<Base *> pool;
   extern int next_id;

   extern Base *find(int id);
   extern bool destroy(int id);
};



