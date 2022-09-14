#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



