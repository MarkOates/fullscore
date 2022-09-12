#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class ToggleRest : public Transforms::Base
   {
   public:
      ToggleRest();
      ~ToggleRest();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



