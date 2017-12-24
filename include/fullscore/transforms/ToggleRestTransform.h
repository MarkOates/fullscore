#pragma once



#include <fullscore/transforms/Base.h>



namespace Transform
{
   class ToggleRest : public Transform::Base
   {
   public:
      ToggleRest();
      ~ToggleRest();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



