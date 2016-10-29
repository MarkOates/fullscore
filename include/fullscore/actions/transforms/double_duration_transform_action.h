#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class DoubleDurationTransform : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      DoubleDurationTransform(std::vector<Note> *notes);
      ~DoubleDurationTransform();

      bool execute() override;
   };
};




