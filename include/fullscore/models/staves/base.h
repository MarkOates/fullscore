#pragma once



#include <string>



namespace Staff
{
   class Base
   {
   private:
      std::string type;
      int id;

   public:
      Base(std::string type);
      virtual ~Base();
      std::string get_type();
      bool is_type(std::string type);
      int get_id();
   };
};



