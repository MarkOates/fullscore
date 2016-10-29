#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class ToggleRest : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      ToggleRest(std::vector<Note> *notes);
      ~ToggleRest();

      bool execute() override;
   };
};




