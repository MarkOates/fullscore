#pragma once



#include <vector>
#include <fullscore/actions/Base.h>



class Note;

namespace Action
{
   namespace Transform
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



