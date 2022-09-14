#pragma once



#include <fullscore/Transforms/Base.hpp>

#include <fullscore/models/Note.hpp>



namespace Transforms
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



