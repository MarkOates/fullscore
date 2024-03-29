#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



