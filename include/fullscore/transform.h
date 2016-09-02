#ifndef __FULLSCORE_TRANSFORM_HEADER
#define __FULLSCORE_TRANSFORM_HEADER




#include <fullscore/note.h>



namespace Transform
{
   class Base
   {
   public:
      virtual std::vector<Note> transform(std::vector<Note> n);
   };
};



#endif
