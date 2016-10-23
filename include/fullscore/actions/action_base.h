#ifndef __FULLSCORE_ACTION_BASE_HEADER
#define __FULLSCORE_ACTION_BASE_HEADER




#include <string>




namespace Action
{
   class Base
   {
   private:
      std::string action_name;

   public:
      Base(std::string action_name);
      ~Base();
      virtual bool execute() = 0;
      std::string get_action_name();
   };
};




#endif
