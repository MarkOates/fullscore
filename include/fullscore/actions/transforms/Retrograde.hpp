#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transforms
   {
      class Retrograde : public Base
      {
      private:
         std::vector<Note> *notes;

      public:
         Retrograde(std::vector<Note> *notes);
         ~Retrograde();

         bool execute() override;
      };
   };
};



