#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class AddDotTransform : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      AddDotTransform(std::vector<Note> *notes);
      ~AddDotTransform();

      bool execute() override;
   };
};




