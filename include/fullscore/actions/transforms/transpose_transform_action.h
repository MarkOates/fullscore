#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class TransposeTransform : public Base
   {
   private:
      Note *note;
      int transposition;

   public:
      TransposeTransform(Note *note, int transposition);
      ~TransposeTransform();

      bool execute() override;
   };
};




