#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
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
};




