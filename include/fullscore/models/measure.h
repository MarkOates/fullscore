#pragma once



#include <string>
#include <vector>
#include <fullscore/models/note.h>



namespace Measure
{
   std::string const TYPE_IDENTIFIER_BASE      = "base";
   std::string const TYPE_IDENTIFIER_BASIC     = "basic";
   std::string const TYPE_IDENTIFIER_REFERENCE = "reference";
   std::string const TYPE_IDENTIFIER_STACK     = "stack";
   std::string const TYPE_IDENTIFIER_STATIC    = "static";

   class Base;

   extern std::vector<Base *> pool;
   extern int next_id;

   extern Base *find(int id);
   extern bool destroy(int id);
};



