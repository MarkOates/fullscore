#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class DoubleDuration : public Base
   {
   public:
      int maximum_duration;

      DoubleDuration();
      ~DoubleDuration();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



