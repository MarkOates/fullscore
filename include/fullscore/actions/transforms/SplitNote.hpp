#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



