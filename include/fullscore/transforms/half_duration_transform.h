#pragma once



#include <fullscore/transforms/base.h>



namespace Transform
{
   class HalfDuration : public Base
   {
   public:
      int minimum_duration;

      HalfDuration();
      ~HalfDuration();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}



