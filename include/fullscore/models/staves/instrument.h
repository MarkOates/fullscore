#pragma once



#include <fullscore/models/staves/base.h>



namespace Staff
{
   class Instrument : public Base
   {
   public:
      Instrument();
      ~Instrument();

      virtual float get_height() override;
   };
};



