#pragma once



#include <vector>
#include <fullscore/actions/base.h>
#include <fullscore/models/Note.h>



class UIGridEditor;

namespace Action
{
   namespace Transform
   {
      class InsertNoteAfter : public Base
      {
      private:
         UIGridEditor *grid_editor;
         std::vector<Note> *notes;
         int at_index;
         Note note;

      public:
         InsertNoteAfter(UIGridEditor *grid_editor, std::vector<Note> *notes, int at_index, Note note);
         ~InsertNoteAfter();

         bool execute() override;
      };
   }
}



