#pragma once



#include <vector>
#include <fullscore/actions/base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class AddDot : public Base
      {
      private:
         Note *note;

      public:
         AddDot(Note *note);
         ~AddDot();

         bool execute() override;
      };
   }
}



