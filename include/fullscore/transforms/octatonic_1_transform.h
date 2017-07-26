#pragma once



#include <fullscore/transforms/base.h>



namespace Transform
{
   class Octatonic1 : public Base
   {
   public:
      Octatonic1();
      ~Octatonic1();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}



