#pragma once



#include <fullscore/models/staves/base.h>



namespace Staff
{
   class Spacer : public Base
   {
   public:
      Spacer();
      ~Spacer();

      virtual float get_height() override;
   };
};



