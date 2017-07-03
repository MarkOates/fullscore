#ifndef __FULLSCORE_INVERT_TRANSFORM_HEADER
#define __FULLSCORE_INVERT_TRANSFORM_HEADER




#include <fullscore/transforms/base.h>




namespace Transform
{
   class Invert : public Base
   {
   public:
      int axis;

      Invert(int axis);
      ~Invert();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif
