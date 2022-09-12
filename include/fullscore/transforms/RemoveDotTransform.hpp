#pragma once



#include <fullscore/transforms/Base.hpp>



namespace Transform
{
   class RemoveDot : public Base
   {
   public:
      RemoveDot();
      ~RemoveDot();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



