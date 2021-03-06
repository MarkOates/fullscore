#pragma once



#include <vector>
#include <fullscore/actions/Base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class AddDotToNote : public Base
      {
      private:
         Note *note;

      public:
         AddDotToNote(Note *note);
         ~AddDotToNote();

         bool execute() override;
      };
   }
}



