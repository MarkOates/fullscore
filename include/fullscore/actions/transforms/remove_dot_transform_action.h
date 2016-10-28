#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class RemoveDotTransform : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      RemoveDotTransform(std::vector<Note> *notes);
      ~RemoveDotTransform();

      bool execute() override;
   };
};




