#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
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



