#ifndef __FULLSCORE_DOUBLE_DURATION_TRANSFORM_HEADER
#define __FULLSCORE_DOUBLE_DURATION_TRANSFORM_HEADER




#include <fullscore/transforms/base.h>




namespace Transform
{
   class DoubleDuration : public Base
   {
   public:
      int maximum_duration;

      DoubleDuration();
      ~DoubleDuration();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif
