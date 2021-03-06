#pragma once



#include <vector>
#include <fullscore/actions/Base.h>



class Note;

namespace Action
{
   namespace Transform
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
   }
}



