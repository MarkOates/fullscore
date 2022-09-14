#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



