#pragma once



#include <fullscore/transforms/Base.h>



namespace Transform
{
   class Retrograde : public Transform::Base
   {
   public:
      Retrograde();
      ~Retrograde();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



