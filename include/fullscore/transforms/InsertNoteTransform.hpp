#pragma once



#include <fullscore/transforms/Base.hpp>

#include <fullscore/models/Note.hpp>



namespace Transform
{
   class InsertNote : public Base
   {
   public:
      int position;
      Note note;

      InsertNote(int position, Note note);
      ~InsertNote();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



