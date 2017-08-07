#pragma once



#include <vector>
#include <fullscore/actions/base.h>



class Note;

namespace Action
{
   class AddDotTransform : public Base
   {
   private:
      Note *note;

   public:
      AddDotTransform(Note *note);
      ~AddDotTransform();

      bool execute() override;
   };
};



