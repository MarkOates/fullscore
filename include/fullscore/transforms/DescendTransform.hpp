#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class Descend : public Base
   {
   public:
      Descend();
      ~Descend();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



