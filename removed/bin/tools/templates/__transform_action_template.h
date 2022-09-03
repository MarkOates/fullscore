#pragma once



#include <vector>
#include <fullscore/actions/base.h>



class Note;

namespace Action
{
   class CLASS_NAME : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      CLASS_NAME(std::vector<Note> *notes);
      ~CLASS_NAME();

      bool execute() override;
   };
};



