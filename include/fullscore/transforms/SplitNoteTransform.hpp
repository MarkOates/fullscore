#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class SplitNote : public Base
   {
   public:
      SplitNote();
      ~SplitNote();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



