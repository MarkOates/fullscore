#pragma once



#include <vector>
#include <fullscore/actions/Base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class Descend : public Base
      {
      private:
         std::vector<Note> *notes;

      public:
         Descend(std::vector<Note> *notes);
         ~Descend();

         bool execute() override;
      };
   }
}



