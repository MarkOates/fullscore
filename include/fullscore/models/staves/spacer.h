#pragma once



#include <fullscore/models/staves/Base.h>



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



