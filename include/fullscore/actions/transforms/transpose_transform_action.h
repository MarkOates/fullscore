#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class TransposeTransform : public Base
   {
   private:
      std::vector<Note> *notes;
      int transposition;

   public:
      TransposeTransform(std::vector<Note> *notes, int transposition);
      ~TransposeTransform();

      bool execute() override;
   };
};




