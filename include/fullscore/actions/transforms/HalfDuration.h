#pragma once



#include <vector>
#include <fullscore/actions/Base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class HalfDuration : public Base
      {
      private:
         Note *note;

      public:
         HalfDuration(Note *note);
         ~HalfDuration();

         bool execute() override;
      };
   }
}



