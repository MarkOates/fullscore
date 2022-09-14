#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
   {
      class Octatonic1 : public Base
      {
      private:
         std::vector<Note> *notes;

      public:
         Octatonic1(std::vector<Note> *notes);
         ~Octatonic1();

         bool execute() override;
      };
   }
}



