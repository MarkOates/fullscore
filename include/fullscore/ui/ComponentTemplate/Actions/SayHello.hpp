#pragma once


#include <fullscore/actions/Base.h>


namespace UI::ComponentTemplate::Actions
{
   class SayHello : public Action::Base
   {
   public:
      SayHello();
      ~SayHello();

      bool execute() override;
   };
};


