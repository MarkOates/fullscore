#pragma once



#include <fullscore/transforms/base.h>



namespace Transform
{
   class Descend : public Base
   {
   public:
      Descend();
      ~Descend();

      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
};



