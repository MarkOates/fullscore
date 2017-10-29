#pragma once



#include <fullscore/models/staves/base.h>



namespace Staff
{
   class MeasureNumbers : public Base
   {
   public:
      MeasureNumbers();
      ~MeasureNumbers();

      virtual float get_height() override;
   };
};



