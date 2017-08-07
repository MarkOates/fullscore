#pragma once



#include <string>



namespace Action
{
   class Base
   {
   private:
      std::string action_name;

   public:
      Base(std::string action_name);
      virtual ~Base();
      virtual bool execute() = 0;
      std::string get_action_name();
   };
};



