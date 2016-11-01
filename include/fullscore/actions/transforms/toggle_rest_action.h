#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
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
};




