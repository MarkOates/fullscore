#pragma once



#include <vector>
#include <fullscore/actions/base.h>
#include <fullscore/models/Note.h>



namespace Action
{
   namespace Transform
   {
      class AppendNote : public Base
      {
      private:
         std::vector<Note> *notes;
         Note note;

      public:
         AppendNote(std::vector<Note> *notes, Note note);
         ~AppendNote();

         bool execute() override;
      };
   }
}



