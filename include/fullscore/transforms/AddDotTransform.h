#pragma once



#include <fullscore/transforms/Base.h>



namespace Transform
{
   class AddDot : public Base
   {
   public:
      AddDot();
      ~AddDot();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



