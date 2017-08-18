#pragma once



#include <vector>
#include <fullscore/models/Note.h>



namespace Transform
{
   class Base
   {
   private:
      std::string identifier;

   public:
      Base(std::string identifier);
      ~Base();
      virtual std::vector<Note> transform(std::vector<Note> source);
      std::string get_identifier();
   };
};



