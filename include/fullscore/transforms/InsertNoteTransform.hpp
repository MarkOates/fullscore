#pragma once



#include <fullscore/Transforms/Base.hpp>

#include <fullscore/models/Note.hpp>



namespace Transforms
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



