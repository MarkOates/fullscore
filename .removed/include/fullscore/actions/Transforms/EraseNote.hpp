#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



