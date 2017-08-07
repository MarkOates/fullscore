#pragma once



#include <vector>
#include <fullscore/actions/base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class DoubleDurationTransform : public Base
      {
      private:
         Note *note;

      public:
         DoubleDurationTransform(Note *note);
         ~DoubleDurationTransform();

         bool execute() override;
      };
   }
}



