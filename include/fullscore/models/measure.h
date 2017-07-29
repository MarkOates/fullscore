#pragma once



#include <vector>
#include <fullscore/models/note.h>



namespace Measure
{
   MEASURE_TYPE_IDENTIFIER_BASE = "base";
   MEASURE_TYPE_IDENTIFIER_BASIC = "basic";
   MEASURE_TYPE_IDENTIFIER_REFERENCE = "reference";
   MEASURE_TYPE_IDENTIFIER_STACK = "stack";
   MEASURE_TYPE_IDENTIFIER_STATIC = "static";

   class Base;

   extern std::vector<Base *> pool;
   extern int next_id;

   extern Base *find(int id);
   extern bool destroy(int id);
};



