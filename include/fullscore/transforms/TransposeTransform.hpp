#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class Transpose : public Transforms::Base
   {
   public:
      int transposition;
      Transpose(int transposition);
      ~Transpose();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



