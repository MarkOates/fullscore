#pragma once



#include <string>
#include <vector>



namespace Staff
{
   enum find_option_t
   {
      FIND_OPTION_NONE = 0,
      FIND_OPTION_INCLUDE_NOT_FOUND,
      FIND_OPTION_RAISE_NOT_FOUND,
   };

   int const NO_RECORD = -1;

   class Base;

   extern std::vector<Base *> pool;
   extern int next_id;

   extern bool push_back(Base *measure);
   extern bool remove(int id);
   extern int count();
   extern Base *find(int id, find_option_t find_option=FIND_OPTION_NONE);
   extern std::vector<Base *> find(std::vector<int> ids, find_option_t find_option=FIND_OPTION_NONE);
   extern bool destroy(int id);
};



