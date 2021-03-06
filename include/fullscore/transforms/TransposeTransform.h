#pragma once



#include <fullscore/transforms/Base.h>



namespace Transform
{
   class Transpose : public Transform::Base
   {
   public:
      int transposition;
      Transpose(int transposition);
      ~Transpose();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



