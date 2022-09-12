#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class RemoveDot : public Base
   {
   public:
      RemoveDot();
      ~RemoveDot();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



