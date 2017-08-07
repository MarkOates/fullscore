#pragma once



#include <vector>
#include <fullscore/actions/base.h>
#include <fullscore/models/note.h>



namespace Action
{
   namespace Transform
   {
      class AppendNoteTransform : public Base
      {
      private:
         std::vector<Note> *notes;
         Note note;

      public:
         AppendNoteTransform(std::vector<Note> *notes, Note note);
         ~AppendNoteTransform();

         bool execute() override;
      };
   }
}



