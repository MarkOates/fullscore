#pragma once



#include <fullscore/models/staves/base.h>
#include <allegro_flare/attributes.h>



namespace Staff
{
   class Instrument : public Base
   {
   public:
      Attributes attributes;

      Instrument(std::string name = std::string());
      ~Instrument();

      virtual float get_height() override;
   };
};



