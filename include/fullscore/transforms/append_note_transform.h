#pragma once



#include <fullscore/transforms/base.h>

#include <fullscore/models/Note.h>



namespace Transform
{
   class AppendNote : public Base
   {
   public:
      Note note;

      AppendNote(Note note);
      ~AppendNote();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



