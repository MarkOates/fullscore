#pragma once



#include <fullscore/transforms/Base.h>



namespace Transform
{
   class SplitNote : public Base
   {
   public:
      SplitNote();
      ~SplitNote();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



