#ifndef __FULLSCORE_RETROGRADE_TRANSFORM_HEADER
#define __FULLSCORE_RETROGRADE_TRANSFORM_HEADER




#include <fullscore/transforms/transform_base.h>




namespace Transform
{
   class Retrograde : public Transform::Base
   {
   public:
      Retrograde();
      ~Retrograde();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};




#endif
