#ifndef __FULLSCORE_TRANSPOSE_TRANSFORM_HEADER
#define __FULLSCORE_TRANSPOSE_TRANSFORM_HEADER




#include <fullscore/transform_base.h>




namespace Transform
{
   class Transpose : public Transform::Base
   {
   public:
      int transposition;
      Transpose(int transposition);
      ~Transpose();
      std::vector<Note> transform(std::vector<Note> notes) override;
   };
};




#endif
