#pragma once



#include <fullscore/Transforms/Base.hpp>


namespace Transforms
{
   class Ascend : public Transforms::Base
   {
   public:
      constexpr static const char TYPE[] = "Ascend";

      Ascend();
      ~Ascend();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



