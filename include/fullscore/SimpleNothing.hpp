#pragma once


#include <string>


namespace fullscore
{
   class SimpleNothing
   {
   private:
      std::string message;

   public:
      SimpleNothing(std::string message="");
      ~SimpleNothing();


      std::string get_message();
   void output_message();
   };
}



