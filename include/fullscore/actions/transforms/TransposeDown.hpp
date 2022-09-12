#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transform
   {
      class TransposeDown : public Base
      {
      private:
         Note *note;

      public:
         TransposeDown(Note *note);
         ~TransposeDown();

         bool execute() override;
      };
   }
}



