#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class Invert : public Base
   {
   public:
      int axis;

      Invert(int axis);
      ~Invert();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



