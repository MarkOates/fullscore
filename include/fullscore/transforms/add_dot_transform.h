#pragma once



#include <fullscore/transforms/base.h>



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



