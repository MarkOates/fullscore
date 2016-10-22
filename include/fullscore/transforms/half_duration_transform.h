#ifndef __FULLSCORE_HALF_DURATION_TRANSFORM_HEADER
#define __FULLSCORE_HALF_DURATION_TRANSFORM_HEADER




#include <fullscore/transforms/transform_base.h>




namespace Transform
{
   class HalfDuration : public Base
   {
   public:
      int minimum_duration;

      HalfDuration();
      ~HalfDuration();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif
