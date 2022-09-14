#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>
#include <fullscore/models/Note.hpp>



namespace Action
{
   namespace Transforms
   {
      class InsertNote : public Base
      {
      private:
         std::vector<Note> *notes;
         int at_index;
         Note note;

      public:
         InsertNote(std::vector<Note> *notes, int at_index, Note note);
         ~InsertNote();

         bool execute() override;
      };
   }
}



