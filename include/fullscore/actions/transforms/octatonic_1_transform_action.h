#pragma once



#include <vector>
#include <fullscore/actions/action_base.h>



class Note;

namespace Action
{
   class Octatonic1Transform : public Base
   {
   private:
      std::vector<Note> *notes;

   public:
      Octatonic1Transform(std::vector<Note> *notes);
      ~Octatonic1Transform();

      bool execute() override;
   };
};



