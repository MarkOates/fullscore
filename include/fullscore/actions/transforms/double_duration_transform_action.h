#pragma once



#include <vector>
#include <fullscore/actions/base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class DoubleDuration : public Base
      {
      private:
         Note *note;

      public:
         DoubleDuration(Note *note);
         ~DoubleDuration();

         bool execute() override;
      };
   }
}



