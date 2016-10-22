#ifndef __FULLSCORE_TRANSFORM_BASE_HEADER
#define __FULLSCORE_TRANSFORM_BASE_HEADER




#include <fullscore/models/note.h>



namespace Transform
{
   class Base
   {
   public:
      Base();
      ~Base();
      virtual std::vector<Note> transform(std::vector<Note> source);
   };
};




#endif
