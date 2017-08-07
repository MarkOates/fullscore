#pragma once



#include <vector>
#include <fullscore/actions/base.h>
#include <fullscore/models/note.h>



namespace Action
{
   class InsertNoteTransform : public Base
   {
   private:
      std::vector<Note> *notes;
      int at_index;
      Note note;

   public:
      InsertNoteTransform(std::vector<Note> *notes, int at_index, Note note);
      ~InsertNoteTransform();

      bool execute() override;
   };
};



