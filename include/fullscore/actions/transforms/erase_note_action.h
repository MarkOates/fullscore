#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class EraseNote : public Base
   {
   private:
      std::vector<Note> *notes;
      int index;

   public:
      EraseNote(std::vector<Note> *notes, int index);
      ~EraseNote();

      bool execute() override;
   };
};




