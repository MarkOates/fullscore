#pragma once



#include <fullscore/models/staves/Base.hpp>
#include <AllegroFlare/Attributes.hpp>



namespace Staff
{
   class Instrument : public Base
   {
   public:
      AllegroFlare::Attributes attributes;

      Instrument(std::string name = std::string());
      ~Instrument();

      virtual float get_height() override;
   };
};



