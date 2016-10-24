#ifndef __FULLSCORE_REMOVE_DOT_TRANSFORM_HEADER
#define __FULLSCORE_REMOVE_DOT_TRANSFORM_HEADER




#include <fullscore/transforms/transform_base.h>




namespace Transform
{
   class RemoveDot : public Base
   {
   public:
      RemoveDot();
      ~RemoveDot();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif
