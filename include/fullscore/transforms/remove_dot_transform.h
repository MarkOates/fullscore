#pragma once



#include <fullscore/transforms/base.h>



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



