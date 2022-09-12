#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>
#include <fullscore/models/Note.hpp>



namespace Action
{
   namespace Transform
   {
      class InsertNoteAfter : public Base
      {
      private:
         std::vector<Note> *notes;
         int at_index;
         Note note;

      public:
         InsertNoteAfter(std::vector<Note> *notes, int at_index, Note note);
         ~InsertNoteAfter();

         bool execute() override;
      };
   }
}



