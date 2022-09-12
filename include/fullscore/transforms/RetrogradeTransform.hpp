#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class Retrograde : public Transforms::Base
   {
   public:
      Retrograde();
      ~Retrograde();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



