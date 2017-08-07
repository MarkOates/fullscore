#pragma once



#include <vector>
#include <fullscore/actions/action_base.h>



class Note;

namespace Action
{
   class HalfDurationTransform : public Base
   {
   private:
      Note *note;

   public:
      HalfDurationTransform(Note *note);
      ~HalfDurationTransform();

      bool execute() override;
   };
};



