#pragma once



#include <string>
#include <vector>
#include <fullscore/models/staves/Base.hpp>



namespace StaffRepository
{
   std::string const TYPE_IDENTIFIER_NONE       = "none";
   std::string const TYPE_IDENTIFIER_INSTRUMENT = "instrument";

   enum find_option_t
   {
      FIND_OPTION_NONE = 0,
      FIND_OPTION_INCLUDE_NOT_FOUND,
      FIND_OPTION_RAISE_NOT_FOUND,
   };

   int const NO_RECORD = -1;

   //class Base;

   extern std::vector<Staff::Base *> pool;
   extern int next_id;

   extern bool push_back(Staff::Base *measure);
   extern bool remove(int id);
   extern int count();
   extern Staff::Base *find(int id, find_option_t find_option=FIND_OPTION_NONE);
   extern std::vector<Staff::Base *> find(std::vector<int> ids, find_option_t find_option=FIND_OPTION_NONE);
   extern bool destroy(int id);
   extern bool destroy_all();
   extern Staff::Base *find_first_of_type(std::string type);
};



