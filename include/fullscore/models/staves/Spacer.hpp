#pragma once



#include <fullscore/models/staves/Base.hpp>



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



