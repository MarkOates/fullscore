#pragma once



#include <fullscore/transforms/Base.hpp>



namespace Transform
{
   class HalfDuration : public Base
   {
   public:
      int minimum_duration;

      HalfDuration();
      ~HalfDuration();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



