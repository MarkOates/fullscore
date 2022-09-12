#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class Octatonic1 : public Base
   {
   public:
      Octatonic1();
      ~Octatonic1();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



