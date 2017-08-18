#pragma once



#include <fullscore/transforms/base.h>



namespace Transform
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



