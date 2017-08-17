#pragma once



#include <fullscore/transforms/base.h>

#include <fullscore/models/Note.h>



namespace Transform
{
   class InsertNote : public Base
   {
   public:
      int position;
      Note note;

      InsertNote(int position, Note note);
      ~InsertNote();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}



