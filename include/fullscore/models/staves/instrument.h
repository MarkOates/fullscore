#pragma once



#include <fullscore/models/staves/base.h>



namespace Staff
{
   class Instrument : public Base
   {
   public:
      Instrument(std::string name = std::string());
      ~Instrument();

      virtual float get_height() override;
   };
};



