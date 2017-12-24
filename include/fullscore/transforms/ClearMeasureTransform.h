#pragma once



#include <fullscore/transforms/Base.h>



namespace Transform
{
   class ClearMeasure : public Transform::Base
   {
   public:
      ClearMeasure();
      ~ClearMeasure();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};



