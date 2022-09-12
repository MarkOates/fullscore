#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transform
   {
      class Ascend : public Base
      {
      private:
         std::vector<Note> *notes;

      public:
         Ascend(std::vector<Note> *notes);
         ~Ascend();

         bool execute() override;
      };
   }
}



