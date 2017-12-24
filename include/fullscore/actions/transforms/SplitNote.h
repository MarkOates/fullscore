#pragma once



#include <vector>
#include <fullscore/actions/Base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class SplitNote : public Base
      {
      private:
         std::vector<Note> *notes;

      public:
         SplitNote(std::vector<Note> *notes);
         ~SplitNote();

         bool execute() override;
      };
   };
};



