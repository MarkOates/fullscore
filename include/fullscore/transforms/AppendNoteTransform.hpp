#pragma once



#include <fullscore/transforms/Base.hpp>

#include <fullscore/models/Note.hpp>



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



