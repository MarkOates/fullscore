#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
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
};




