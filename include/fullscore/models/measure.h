#pragma once



#include <string>
#include <vector>
#include <fullscore/models/Note.h>



namespace Measure
{
   std::string const TYPE_IDENTIFIER_BASE                    = "base";
   std::string const TYPE_IDENTIFIER_BASIC                   = "basic";
   std::string const TYPE_IDENTIFIER_PLOTTED                 = "plotted";
   std::string const TYPE_IDENTIFIER_REFERENCE_BY_ID         = "reference_by_id";
   std::string const TYPE_IDENTIFIER_REFERENCE_BY_COORDINATE = "reference_by_coordinate";
   std::string const TYPE_IDENTIFIER_STACK                   = "stack";
   std::string const TYPE_IDENTIFIER_STATIC                  = "static";

   int const NO_RECORD = -1;
   typedef int measure_id_t;

   class Base;

   extern std::vector<Base *> pool;
   extern int next_id;

   extern bool push_back(Base *measure);
   extern bool remove(int id);
   extern int count();
   extern Base *find(int id, bool raise_not_found=false);
   extern std::vector<Base *> find(std::vector<int> ids);
   extern bool destroy(int id);
};



