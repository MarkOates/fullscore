#pragma once



#include <fullscore/transforms/Base.hpp>



namespace Transform
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



