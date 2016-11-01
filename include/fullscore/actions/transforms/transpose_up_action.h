#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
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
};



