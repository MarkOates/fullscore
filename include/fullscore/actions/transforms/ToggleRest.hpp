#pragma once



#include <vector>
#include <fullscore/actions/Base.hpp>



class Note;

namespace Action
{
   namespace Transform
   {
      class ToggleRest : public Base
      {
      private:
         Note *note;

      public:
         ToggleRest(Note *note);
         ~ToggleRest();

         bool execute() override;
      };
   }
}



