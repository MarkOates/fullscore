#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class Ascend : public Base
   {
   public:
      Ascend();
      ~Ascend();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



