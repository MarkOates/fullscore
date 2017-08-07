#pragma once



#include <vector>
#include <fullscore/actions/action_base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class Invert : public Base
      {
      private:
         Note *note;
         int axis;

      public:
         Invert(Note *note, int axis=0);
         ~Invert();

         bool execute() override;
      };
   };
};



