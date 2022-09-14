#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
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



