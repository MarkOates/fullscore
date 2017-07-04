#pragma once



#include <fullscore/transforms/base.h>



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



