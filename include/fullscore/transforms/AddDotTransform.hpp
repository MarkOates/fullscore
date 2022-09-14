#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class AddDot : public Base
   {
   public:
      AddDot();
      ~AddDot();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



