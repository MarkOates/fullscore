#ifndef __FULLSCORE_DOUBLE_DURATION_TRANSFORM_HEADER
#define __FULLSCORE_DOUBLE_DURATION_TRANSFORM_HEADER




#include <fullscore/transform.h>




namespace Transform
{
   class DoubleDuration : public Base
   {
   public:
      DoubleDuration();
      ~DoubleDuration();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif
