#pragma once



#include <fullscore/transforms/Base.hpp>



namespace Transform
{
   class Ascend : public Base
   {
   public:
      Ascend();
      ~Ascend();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



