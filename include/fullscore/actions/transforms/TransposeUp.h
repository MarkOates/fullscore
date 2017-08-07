#pragma once



#include <vector>
#include <fullscore/actions/base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class TransposeUp : public Base
      {
      private:
         Note *note;

      public:
         TransposeUp(Note *note);
         ~TransposeUp();

         bool execute() override;
      };
   }
}



