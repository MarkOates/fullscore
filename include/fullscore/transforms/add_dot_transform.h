#ifndef __FULLSCORE_ADD_DOT_TRANSFORM_HEADER
#define __FULLSCORE_ADD_DOT_TRANSFORM_HEADER




#include <fullscore/transforms/transform_base.h>




namespace Transform
{
   class AddDot : public Base
   {
   public:
      AddDot();
      ~AddDot();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif
