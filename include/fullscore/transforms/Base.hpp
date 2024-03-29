#pragma once



#include <vector>
#include <fullscore/models/Note.hpp>



namespace Transforms
{
   class Base
   {
   private:
      std::string identifier;

   public:
      Base(std::string identifier);
      virtual ~Base();
      virtual std::vector<Note> transform(std::vector<Note> source);
      std::string get_identifier();
   };
};



