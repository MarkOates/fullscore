#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class ClearMeasure : public Transforms::Base
   {
   public:
      ClearMeasure();
      ~ClearMeasure();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



