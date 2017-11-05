#pragma once



#include <fullscore/models/grid_horizontal_coordinate.h>
#include <string>
#include <vector>



namespace Measure { class Base; }



namespace Staff
{
   class Base
   {
   private:
      std::string type;
      int id;
      std::string name;

   public:
      Base(std::string type, std::string name=std::string());
      virtual ~Base();
      std::string get_type();
      bool is_type(std::string type);
      int get_id();
      void set_name(std::string name);
      std::string get_name();

      virtual float get_height() = 0;
   };
};



