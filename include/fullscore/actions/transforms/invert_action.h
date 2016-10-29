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
         std::vector<Note> *notes;
         int axis;

      public:
         Invert(std::vector<Note> *notes, int axis=0);
         ~Invert();

         bool execute() override;
      };
   };
};




