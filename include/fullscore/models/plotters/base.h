#pragma once



#include <string>



namespace Plotter
{
   class Base
   {
   private:
      std::string type;

   public:
      Base(std::string type);
      virtual ~Base();

      virtual bool plot() = 0;
   };
}



