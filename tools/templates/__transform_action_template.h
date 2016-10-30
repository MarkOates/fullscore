#pragma once




#include <vector>
#include <fullscore/actions/action_base.h>




class Note;

namespace Action
{
   class TEMPLATE : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      TEMPLATE(std::vector<Note> *notes);
      ~TEMPLATE();

      bool execute() override;
   };
};




