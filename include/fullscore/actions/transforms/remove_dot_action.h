#pragma once



#include <vector>
#include <fullscore/actions/base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class RemoveDot : public Base
      {
      private:
         Note *note;

      public:
         RemoveDot(Note *note);
         ~RemoveDot();

         bool execute() override;
      };
   }
}



