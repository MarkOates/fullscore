#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>
#include <fullscore/models/note.h>




namespace Action
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
};




