#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



