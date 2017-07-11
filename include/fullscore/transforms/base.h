#ifndef __FULLSCORE_TRANSFORM_BASE_HEADER
#define __FULLSCORE_TRANSFORM_BASE_HEADER




#include <vector>
#include <fullscore/models/note.h>




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
   };
};




#endif
