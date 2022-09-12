#pragma once



#include <fullscore/transforms/Base.hpp>



namespace Transform
{
   class Descend : public Base
   {
   public:
      Descend();
      ~Descend();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



