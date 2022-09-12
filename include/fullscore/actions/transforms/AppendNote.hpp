#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>
#include <fullscore/models/Note.hpp>



namespace Action
{
   namespace Transform
   {
      class AppendNote : public Base
      {
      private:
         std::vector<Note> *notes;
         Note note;

      public:
         AppendNote(std::vector<Note> *notes, Note note);
         ~AppendNote();

         bool execute() override;
      };
   }
}



