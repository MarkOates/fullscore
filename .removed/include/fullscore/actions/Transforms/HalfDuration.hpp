#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



