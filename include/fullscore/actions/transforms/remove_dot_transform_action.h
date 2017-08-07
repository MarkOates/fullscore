#pragma once



#include <vector>
#include <fullscore/actions/action_base.h>



class Note;

namespace Action
{
   class RemoveDotTransform : public Base
   {
   private:
      Note *note;

   public:
      RemoveDotTransform(Note *note);
      ~RemoveDotTransform();

      bool execute() override;
   };
};



