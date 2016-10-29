#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class HalfDurationTransform : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      HalfDurationTransform(std::vector<Note> *notes);
      ~HalfDurationTransform();

      bool execute() override;
   };
};




