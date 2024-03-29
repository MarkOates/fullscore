#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



